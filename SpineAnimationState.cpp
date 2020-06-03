//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationState.h"


void SpineAnimationState::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_animation", "anim_name", "loop", "track"), &SpineAnimationState::set_animation);
}

SpineAnimationState::SpineAnimationState():animation_state(NULL) {

}

SpineAnimationState::~SpineAnimationState() {
	if(animation_state)
	{
		delete animation_state;
		animation_state = NULL;
	}
}

void SpineAnimationState::load_animation_state(Ref<SpineAnimationStateDataResource> ad) {
	if(animation_state)
	{
		delete animation_state;
		animation_state = NULL;
	}
	animation_state = new spine::AnimationState(ad->get_animation_state_data());
}

void SpineAnimationState::set_animation(const String &anim_name, bool loop, int track) {
	if(animation_state)
	{
		animation_state->setAnimation(track, spine::String(anim_name.utf8()), loop);
	}else{
		print_error("The animation state is not loaded yet!");
	}
}