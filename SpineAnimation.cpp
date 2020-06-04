//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineAnimation.h"

void SpineAnimation::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_anim_name"), &SpineAnimation::get_anim_name);
	ClassDB::bind_method(D_METHOD("get_duration"), &SpineAnimation::get_duration);
	ClassDB::bind_method(D_METHOD("set_duration", "v"), &SpineAnimation::set_duration);
}

SpineAnimation::SpineAnimation():animation(NULL) {}
SpineAnimation::~SpineAnimation(){}

String SpineAnimation::get_anim_name() {
	return animation->getName().buffer();
}

float SpineAnimation::get_duration() {
	return animation->getDuration();
}
void SpineAnimation::set_duration(float v) {
	animation->setDuration(v);
}