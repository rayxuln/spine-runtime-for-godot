//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationStateDataResource.h"

SpineAnimationStateDataResource::SpineAnimationStateDataResource():animation_state_data(NULL),animation_state_data_created(false),default_mix(0.5f) {

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
	ClassDB::bind_method(D_METHOD("get_spine_object"), &SpineAnimationStateDataResource::get_skeleton);
	ClassDB::bind_method(D_METHOD("_on_skeleton_data_loaded"), &SpineAnimationStateDataResource::_on_skeleton_data_loaded);
	ClassDB::bind_method(D_METHOD("is_animation_state_data_created"), &SpineAnimationStateDataResource::is_animation_state_data_created);
	ClassDB::bind_method(D_METHOD("_on_skeleton_data_changed"), &SpineAnimationStateDataResource::_on_skeleton_data_changed);
	ClassDB::bind_method(D_METHOD("set_default_mix", "mix"), &SpineAnimationStateDataResource::set_default_mix);
	ClassDB::bind_method(D_METHOD("get_default_mix"), &SpineAnimationStateDataResource::get_default_mix);
	ClassDB::bind_method(D_METHOD("get_mix", "from", "to"), &SpineAnimationStateDataResource::get_mix);
	ClassDB::bind_method(D_METHOD("set_mix", "from", "to", "mix"), &SpineAnimationStateDataResource::set_mix);

	ADD_SIGNAL(MethodInfo("animation_state_data_created"));
	ADD_SIGNAL(MethodInfo("skeleton_data_res_changed"));
	ADD_SIGNAL(MethodInfo("animation_state_data_changed"));

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonDataResource"), "set_skeleton", "get_spine_object");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "default_mix", PropertyHint::PROPERTY_HINT_EXP_RANGE, "0,1,0.01"), "set_default_mix", "get_default_mix");
}

void SpineAnimationStateDataResource::set_skeleton(const Ref<SpineSkeletonDataResource> &s) {
	skeleton = s;

	_on_skeleton_data_changed();
	if(skeleton.is_valid())
	{
		skeleton->connect("skeleton_data_loaded", this, "_on_skeleton_data_loaded");
		skeleton->connect("atlas_res_changed", this, "_on_skeleton_data_changed");
		skeleton->connect("skeleton_json_res_changed", this, "_on_skeleton_data_changed");

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
//			print_line("Animation state data deleted.");
		}
	}


}
Ref<SpineSkeletonDataResource> SpineAnimationStateDataResource::get_skeleton() {
	return skeleton;
}

void SpineAnimationStateDataResource::set_default_mix(float m) {
	default_mix = m;
	if(!is_animation_state_data_created())
	{
//		ERR_PRINT("'set_default_mix' fail. Animation state data is not created!");
		return;
	}
	animation_state_data->setDefaultMix(((m >= 0 && m <= 1) ? m : m <= 0 ? 0 : 1));
//	emit_signal("animation_state_data_changed");
}
float SpineAnimationStateDataResource::get_default_mix() {
	if(!is_animation_state_data_created())
	{
//		ERR_PRINT("'get_default_mix' fail. Animation state data is not created!");
		return default_mix;
	}
	default_mix = animation_state_data->getDefaultMix();
	return default_mix;
}

void SpineAnimationStateDataResource::set_mix(const String &from, const String &to, float mix_duration) {
	if(!is_animation_state_data_created())
	{
		ERR_PRINT("'set_mix' fail. Animation state data is not created!");
		return;
	}
	auto anim_from = get_skeleton()->find_animation(from);
	auto anim_to = get_skeleton()->find_animation(to);
	if(!anim_from.is_valid())
	{
		ERR_PRINT("'set_mix' fail. From animation animation not found!");
		return;
	}
	if(!anim_to.is_valid())
	{
		ERR_PRINT("'set_mix' fail. To animation animation not found!");
		return;
	}
	animation_state_data->setMix(anim_from->get_spine_object(), anim_to->get_spine_object(), mix_duration);
}
float SpineAnimationStateDataResource::get_mix(const String &from, const String &to) {
	if(!is_animation_state_data_created())
	{
		ERR_PRINT("'set_mix' fail. Animation state data is not created!");
		return 0;
	}
	auto anim_from = get_skeleton()->find_animation(from);
	auto anim_to = get_skeleton()->find_animation(to);
	if(!anim_from.is_valid())
	{
		ERR_PRINT("'set_mix' fail. From animation animation not found!");
		return 0;
	}
	if(!anim_to.is_valid())
	{
		ERR_PRINT("'set_mix' fail. To animation animation not found!");
		return 0;
	}
	return animation_state_data->getMix(anim_from->get_spine_object(), anim_to->get_spine_object());
}

void SpineAnimationStateDataResource::_on_skeleton_data_loaded() {
	animation_state_data = new spine::AnimationStateData(skeleton->get_skeleton_data());
//	print_line("Animation state data created.");


	emit_signal("animation_state_data_created");
	animation_state_data->setDefaultMix(default_mix);
	animation_state_data_created = true;
}

void SpineAnimationStateDataResource::_on_skeleton_data_changed() {
	animation_state_data_created = false;
	if(animation_state_data)
	{
		delete animation_state_data;
		animation_state_data = NULL;
//		print_line("Animation state data deleted.");
	}

//	print_line("skeleton_data_res_changed emitted");
	emit_signal("skeleton_data_res_changed");
}

bool SpineAnimationStateDataResource::is_animation_state_data_created(){
	return animation_state_data_created;
}