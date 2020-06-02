//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSkeletonDataResource.h"



void SpineSkeletonDataResource::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_atlas", "atlas"), &SpineSkeletonDataResource::set_atlas);
	ClassDB::bind_method(D_METHOD("get_atlas"), &SpineSkeletonDataResource::get_atlas);
	ClassDB::bind_method(D_METHOD("is_valid"), &SpineSkeletonDataResource::is_valid);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "atlas", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAtlasResource"), "set_atlas", "get_atlas");
}

Error SpineSkeletonDataResource::load_file(const String &path) {
	print_line(String("Skeleton json data loading: ") + path);
	set_path(path);
	return OK;
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

bool SpineSkeletonDataResource::is_valid() {
	return valid;
}

void SpineSkeletonDataResource::load_res(spine::Atlas *a) {
	auto path = get_path();
	spine::SkeletonJson json(a);
	skeleton_data = json.readSkeletonDataFile(spine::String(path.utf8()));
	if(!skeleton_data)
	{
		print_error(String("Error happened while loading skeleton json data: ") + path);
		print_error(String("Error msg: ") + json.getError().buffer());
		return;
	}

	valid = true;
	print_line("Skeleton json data loaded!");
}

void SpineSkeletonDataResource::set_atlas(const Ref<SpineAtlasResource> &a) {
	atlas = a;
	valid = false;
	if(atlas != NULL)
	{
		load_res(atlas->get_spine_atlas());
	}
}
Ref<SpineAtlasResource> SpineSkeletonDataResource::get_atlas() {
	return atlas;
}