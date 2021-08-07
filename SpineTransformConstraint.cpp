//
// Created by Raymond_Lx on 2020/6/6.
//

#include "SpineTransformConstraint.h"

void SpineTransformConstraint::_bind_methods() {
	ClassDB::bind_method(D_METHOD("update"), &SpineTransformConstraint::update);
	ClassDB::bind_method(D_METHOD("get_data"), &SpineTransformConstraint::get_data);
	ClassDB::bind_method(D_METHOD("get_bones"), &SpineTransformConstraint::get_bones);
	ClassDB::bind_method(D_METHOD("get_target"), &SpineTransformConstraint::get_target);
	ClassDB::bind_method(D_METHOD("set_target", "v"), &SpineTransformConstraint::set_target);
	ClassDB::bind_method(D_METHOD("get_rotate_mix"), &SpineTransformConstraint::get_rotate_mix);
	ClassDB::bind_method(D_METHOD("set_rotate_mix", "v"), &SpineTransformConstraint::set_rotate_mix);
	ClassDB::bind_method(D_METHOD("get_translate_mix"), &SpineTransformConstraint::get_translate_mix);
	ClassDB::bind_method(D_METHOD("set_translate_mix", "v"), &SpineTransformConstraint::set_translate_mix);
	ClassDB::bind_method(D_METHOD("get_scale_mix"), &SpineTransformConstraint::get_scale_mix);
	ClassDB::bind_method(D_METHOD("set_scale_mix", "v"), &SpineTransformConstraint::set_scale_mix);
	ClassDB::bind_method(D_METHOD("get_shear_mix"), &SpineTransformConstraint::get_shear_mix);
	ClassDB::bind_method(D_METHOD("set_shear_mix", "v"), &SpineTransformConstraint::set_shear_mix);
	ClassDB::bind_method(D_METHOD("is_active"), &SpineTransformConstraint::is_active);
	ClassDB::bind_method(D_METHOD("set_active", "v"), &SpineTransformConstraint::set_active);
}

SpineTransformConstraint::SpineTransformConstraint():transform_constraint(NULL) {}
SpineTransformConstraint::~SpineTransformConstraint() {}

void SpineTransformConstraint::update(){
	transform_constraint->update();
}

int SpineTransformConstraint::get_order(){
	return transform_constraint->getOrder();
}

Ref<SpineTransformConstraintData> SpineTransformConstraint::get_data(){
	auto &d = transform_constraint->getData();
	Ref<SpineTransformConstraintData> gd_d(memnew(SpineTransformConstraintData));
	gd_d->set_spine_object(&d);
	return gd_d;
}

Array SpineTransformConstraint::get_bones(){
	auto &bs = transform_constraint->getBones();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for(size_t i=0; i<bs.size(); ++i){
		auto b = bs[i];
		if(b == NULL) gd_bs[i] = Ref<SpineBone>(NULL);
		Ref<SpineBone> gd_b(memnew(SpineBone));
		gd_b->set_spine_object(b);
		gd_bs[i] = gd_b;
	}
	return gd_bs;
}

Ref<SpineBone> SpineTransformConstraint::get_target(){
	auto b = transform_constraint->getTarget();
	if(b == NULL) return NULL;
	Ref<SpineBone> gd_b(memnew(SpineBone));
	gd_b->set_spine_object(b);
	return gd_b;
}
void SpineTransformConstraint::set_target(Ref<SpineBone> v){
	if(v.is_valid()){
		transform_constraint->setTarget(v->get_spine_object());
	} else{
		transform_constraint->setTarget(NULL);
	}
}

float SpineTransformConstraint::get_rotate_mix(){
	return transform_constraint->getRotateMix();
}
void SpineTransformConstraint::set_rotate_mix(float v){
	transform_constraint->setRotateMix(v);
}

float SpineTransformConstraint::get_translate_mix(){
	return transform_constraint->getTranslateMix();
}
void SpineTransformConstraint::set_translate_mix(float v){
	transform_constraint->setTranslateMix(v);
}

float SpineTransformConstraint::get_scale_mix(){
	return transform_constraint->getScaleMix();
}
void SpineTransformConstraint::set_scale_mix(float v){
	transform_constraint->setScaleMix(v);
}

float SpineTransformConstraint::get_shear_mix(){
	return transform_constraint->getShearMix();
}
void SpineTransformConstraint::set_shear_mix(float v){
	transform_constraint->setShearMix(v);
}

bool SpineTransformConstraint::is_active(){
	return transform_constraint->isActive();
}
void SpineTransformConstraint::set_active(bool v){
	transform_constraint->setActive(v);
}