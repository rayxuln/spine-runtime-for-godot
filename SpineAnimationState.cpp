//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineAnimationState.h"


void SpineAnimationState::_bind_methods() {

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