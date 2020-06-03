//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSkeletonDataResource.h"



void SpineSkeletonDataResource::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_atlas_res", "atlas_res"), &SpineSkeletonDataResource::set_atlas_res);
	ClassDB::bind_method(D_METHOD("get_atlas_res"), &SpineSkeletonDataResource::get_atlas_res);
	ClassDB::bind_method(D_METHOD("set_skeleton_json_res", "skeleton_json_res"), &SpineSkeletonDataResource::set_skeleton_json_res);
	ClassDB::bind_method(D_METHOD("get_skeleton_json_res"), &SpineSkeletonDataResource::get_skeleton_json_res);
	ClassDB::bind_method(D_METHOD("is_skeleton_data_loaded"), &SpineSkeletonDataResource::is_skeleton_data_loaded);

	ADD_SIGNAL(MethodInfo("skeleton_data_loaded"));

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "atlas_res", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAtlasResource"), "set_atlas_res", "get_atlas_res");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton_json_res", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonJsonDataResource"), "set_skeleton_json_res", "get_skeleton_json_res");
}

SpineSkeletonDataResource::SpineSkeletonDataResource():valid(false),skeleton_data(NULL) {

}
SpineSkeletonDataResource::~SpineSkeletonDataResource() {
	if(skeleton_data)
	{
		delete skeleton_data;
		skeleton_data = NULL;
	}
}

bool SpineSkeletonDataResource::is_skeleton_data_loaded() {
	return valid;
}

void SpineSkeletonDataResource::load_res(spine::Atlas *a, const String &json_path) {
	auto path = get_path();
	spine::SkeletonJson json(a);
	auto temp_skeleton_data = json.readSkeletonDataFile(spine::String(json_path.utf8()));
	if(!temp_skeleton_data)
	{
		print_error(String("Error happened while loading skeleton json data: ") + path);
		print_error(String("Error msg: ") + json.getError().buffer());
		return;
	}
	if(skeleton_data)
	{
		delete skeleton_data;
		skeleton_data = NULL;
	}
	skeleton_data = temp_skeleton_data;

	valid = true;
	print_line("Skeleton json data loaded!");
}

void SpineSkeletonDataResource::update_skeleton_data() {
	valid = false;
	if(atlas_res != NULL && !skeleton_json_res.is_null())
	{
		load_res(atlas_res->get_spine_atlas(), skeleton_json_res->get_path());
		if(valid)
		{
			emit_signal("skeleton_data_loaded");
		}
	}
}

void SpineSkeletonDataResource::set_atlas_res(const Ref<SpineAtlasResource> &a) {
	atlas_res = a;
	update_skeleton_data();
}
Ref<SpineAtlasResource> SpineSkeletonDataResource::get_atlas_res() {
	return atlas_res;
}

void SpineSkeletonDataResource::set_skeleton_json_res(const Ref<SpineSkeletonJsonDataResource> &s) {
	skeleton_json_res = s;
	update_skeleton_data();
}
Ref<SpineSkeletonJsonDataResource> SpineSkeletonDataResource::get_skeleton_json_res() {
	return skeleton_json_res;
}