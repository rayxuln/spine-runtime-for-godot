//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationStateDataResource.h"

SpineAnimationStateDataResource::SpineAnimationStateDataResource():animation_state_data(NULL),animation_state_data_created(false) {

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
	ClassDB::bind_method(D_METHOD("is_animation_state_data_created"), &SpineAnimationStateDataResource::is_animation_state_data_created);

	ADD_SIGNAL(MethodInfo("animation_state_data_created"));

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonDataResource"), "set_skeleton", "get_skeleton");
}

void SpineAnimationStateDataResource::set_skeleton(const Ref<SpineSkeletonDataResource> &s) {
	skeleton = s;

	if(skeleton.is_valid())
	{
		skeleton->connect("skeleton_data_loaded", this, "_on_skeleton_data_loaded");

		if(skeleton->is_skeleton_data_loaded())
		{
			_on_skeleton_data_loaded();
		}
	}else{
		if(animation_state_data)
		{
			delete animation_state_data;
			animation_state_data = NULL;
			animation_state_data_created = false;
			print_line("Animation state data deleted.");
		}
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
		animation_state_data_created = false;
		print_line("Animation state data deleted.");
	}
	animation_state_data = new spine::AnimationStateData(skeleton->get_skeleton_data());
	print_line("Animation state data created.");


	emit_signal("animation_state_data_created");
	animation_state_data->setDefaultMix(0.5f);
	animation_state_data_created = true;
}

bool SpineAnimationStateDataResource::is_animation_state_data_created(){
	return animation_state_data_created;
}