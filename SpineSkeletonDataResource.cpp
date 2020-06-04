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
	ClassDB::bind_method(D_METHOD("find_bone_index", "bone_name"), &SpineSkeletonDataResource::find_bone_index);
	ClassDB::bind_method(D_METHOD("find_slot_index", "slot_name"), &SpineSkeletonDataResource::find_slot_index);
	ClassDB::bind_method(D_METHOD("find_path_constraint_index", "path_constraint_name"), &SpineSkeletonDataResource::find_path_constraint_index);
	ClassDB::bind_method(D_METHOD("find_animation", "animation_name"), &SpineSkeletonDataResource::find_animation);
	ClassDB::bind_method(D_METHOD("get_sk_name"), &SpineSkeletonDataResource::get_sk_name);
	ClassDB::bind_method(D_METHOD("set_sk_name", "sk_name"), &SpineSkeletonDataResource::set_sk_name);
	ClassDB::bind_method(D_METHOD("get_x"), &SpineSkeletonDataResource::get_x);
	ClassDB::bind_method(D_METHOD("set_x", "v"), &SpineSkeletonDataResource::set_x);
	ClassDB::bind_method(D_METHOD("get_y"), &SpineSkeletonDataResource::get_y);
	ClassDB::bind_method(D_METHOD("set_y", "v"), &SpineSkeletonDataResource::set_y);
	ClassDB::bind_method(D_METHOD("get_width"), &SpineSkeletonDataResource::get_width);
	ClassDB::bind_method(D_METHOD("get_height"), &SpineSkeletonDataResource::get_height);
	ClassDB::bind_method(D_METHOD("get_version"), &SpineSkeletonDataResource::get_version);
	ClassDB::bind_method(D_METHOD("get_fps"), &SpineSkeletonDataResource::get_fps);
	ClassDB::bind_method(D_METHOD("set_fps", "v"), &SpineSkeletonDataResource::set_fps);

	ADD_SIGNAL(MethodInfo("skeleton_data_loaded"));
	ADD_SIGNAL(MethodInfo("atlas_res_changed"));
	ADD_SIGNAL(MethodInfo("skeleton_json_res_changed"));

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
//	print_line("Skeleton json data loaded!");
}

void SpineSkeletonDataResource::update_skeleton_data() {
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
	valid = false;
//	print_line("atlas_res_changed emitted");
	emit_signal("atlas_res_changed");
	update_skeleton_data();
}
Ref<SpineAtlasResource> SpineSkeletonDataResource::get_atlas_res() {
	return atlas_res;
}

void SpineSkeletonDataResource::set_skeleton_json_res(const Ref<SpineSkeletonJsonDataResource> &s) {
	skeleton_json_res = s;
	valid = false;
//	print_line("skeleton_json_res_changed emitted");
	emit_signal("skeleton_json_res_changed");
	update_skeleton_data();
}
Ref<SpineSkeletonJsonDataResource> SpineSkeletonDataResource::get_skeleton_json_res() {
	return skeleton_json_res;
}

#define CHECK_V if(!is_skeleton_data_loaded()){ERR_PRINT("skeleton data has not loaded yet!");return;}
#define CHECK_X(x) if(!is_skeleton_data_loaded()){ERR_PRINT("skeleton data has not loaded yet!");return x;}
#define S_T(x) (spine::String(x.utf8()))
int SpineSkeletonDataResource::find_bone_index(const String &bone_name) {
	CHECK_X(-1);
	return skeleton_data->findBoneIndex(S_T(bone_name));
}
int SpineSkeletonDataResource::find_slot_index(const String &slot_name) {
	CHECK_X(-1);
	return skeleton_data->findSlotIndex(S_T(slot_name));
}
int SpineSkeletonDataResource::find_path_constraint_index(const String &path_constraint_name) {
	CHECK_X(-1);
	return skeleton_data->findPathConstraintIndex(S_T(path_constraint_name));
}
Ref<SpineAnimation> SpineSkeletonDataResource::find_animation(const String &animation_name) {
	CHECK_X(NULL);
	auto a = skeleton_data->findAnimation(S_T(animation_name));
	if(!a) return NULL;
	Ref<SpineAnimation> sa(memnew(SpineAnimation));
	sa->set_spine_object(a);
	return sa;
}
String SpineSkeletonDataResource::get_sk_name() {
	CHECK_X("error");
	return skeleton_data->getName().buffer();
}
void SpineSkeletonDataResource::set_sk_name(const String &v) {
	CHECK_V;
	skeleton_data->setName(S_T(v));
}
float SpineSkeletonDataResource::get_x() {
	CHECK_X(0);
	return skeleton_data->getX();
}
void SpineSkeletonDataResource::set_x(float v) {
	CHECK_V;
	skeleton_data->setX(v);
}
float SpineSkeletonDataResource::get_y() {
	CHECK_X(0);
	return skeleton_data->getY();
}
void SpineSkeletonDataResource::set_y(float v) {
	CHECK_V;
	skeleton_data->setY(v);
}
float SpineSkeletonDataResource::get_width() {
	CHECK_X(0);
	return skeleton_data->getWidth();
}
float SpineSkeletonDataResource::get_height() {
	CHECK_X(0);
	return skeleton_data->getHeight();
}
String SpineSkeletonDataResource::get_version() {
	CHECK_X("error");
	return skeleton_data->getVersion().buffer();
}
float SpineSkeletonDataResource::get_fps() {
	CHECK_X(0);
	return skeleton_data->getFps();
}
void SpineSkeletonDataResource::set_fps(float v) {
	CHECK_V;
	skeleton_data->setFps(v);
}
#undef S_T
#undef CHECK_V
#undef CHECK_X