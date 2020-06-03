//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationStateDataResource.h"

SpineAnimationStateDataResource::SpineAnimationStateDataResource():animation_state_data(NULL) {

}
SpineAnimationStateDataResource::~SpineAnimationStateDataResource() {
	if(animation_state_data)
	{
		delete animation_state_data;
		animation_state_data = NULL;
	}
}

void SpineAnimationStateDataResource::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_skeleton", "skeleton"), &SpineAnimationStateDataResource::set_skeleton);
	ClassDB::bind_method(D_METHOD("get_skeleton"), &SpineAnimationStateDataResource::get_skeleton);
	ClassDB::bind_method(D_METHOD("_on_skeleton_data_loaded"), &SpineAnimationStateDataResource::_on_skeleton_data_loaded);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonDataResource"), "set_skeleton", "get_skeleton");
}

void SpineAnimationStateDataResource::set_skeleton(const Ref<SpineSkeletonDataResource> &s) {
	skeleton = s;

	if(!skeleton.is_null())
	{
		skeleton->connect("skeleton_data_loaded", this, "_on_skeleton_data_loaded");
	}


}
Ref<SpineSkeletonDataResource> SpineAnimationStateDataResource::get_skeleton() {
	return skeleton;
}

void SpineAnimationStateDataResource::_on_skeleton_data_loaded() {
	if(animation_state_data)
	{
		delete animation_state_data;
		animation_state_data = NULL;
		print_line("Animation state data deleted.");
	}
	if(skeleton->is_skeleton_data_loaded())
	{
		print_line("starting creat animation_state_data");
		animation_state_data = new spine::AnimationStateData(skeleton->get_skeleton_data());
		print_line("Animation state data created.");

		animation_state_data->setDefaultMix(0.5f);
	}
}