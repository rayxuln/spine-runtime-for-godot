//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpinePathConstraintData.h"


void SpinePathConstraintData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_all_bone_data"), &SpinePathConstraintData::get_bones);
	ClassDB::bind_method(D_METHOD("get_target"), &SpinePathConstraintData::get_target);
	ClassDB::bind_method(D_METHOD("set_target", "V"), &SpinePathConstraintData::set_target);
	ClassDB::bind_method(D_METHOD("get_position_mode"), &SpinePathConstraintData::get_position_mode);
	ClassDB::bind_method(D_METHOD("set_position_mode", "V"), &SpinePathConstraintData::set_position_mode);
	ClassDB::bind_method(D_METHOD("get_spacing_mode"), &SpinePathConstraintData::get_spacing_mode);
	ClassDB::bind_method(D_METHOD("set_spacing_mode", "V"), &SpinePathConstraintData::set_spacing_mode);
	ClassDB::bind_method(D_METHOD("get_rotate_mode"), &SpinePathConstraintData::get_rotate_mode);
	ClassDB::bind_method(D_METHOD("set_rotate_mode", "V"), &SpinePathConstraintData::set_rotate_mode);
	ClassDB::bind_method(D_METHOD("get_offset_rotation"), &SpinePathConstraintData::get_offset_rotation);
	ClassDB::bind_method(D_METHOD("set_offset_rotation", "V"), &SpinePathConstraintData::set_offset_rotation);
	ClassDB::bind_method(D_METHOD("get_position"), &SpinePathConstraintData::get_position);
	ClassDB::bind_method(D_METHOD("set_position", "V"), &SpinePathConstraintData::set_position);
	ClassDB::bind_method(D_METHOD("get_spacing"), &SpinePathConstraintData::get_spacing);
	ClassDB::bind_method(D_METHOD("set_spacing", "V"), &SpinePathConstraintData::set_spacing);
	ClassDB::bind_method(D_METHOD("get_rotate_mix"), &SpinePathConstraintData::get_rotate_mix);
	ClassDB::bind_method(D_METHOD("set_rotate_mix", "V"), &SpinePathConstraintData::set_rotate_mix);
	ClassDB::bind_method(D_METHOD("get_translate_mix"), &SpinePathConstraintData::get_translate_mix);
	ClassDB::bind_method(D_METHOD("set_translate_mix", "V"), &SpinePathConstraintData::set_translate_mix);

	BIND_ENUM_CONSTANT(POSITIONMODE_FIXED);
	BIND_ENUM_CONSTANT(POSITIONMODE_PERCENT);

	BIND_ENUM_CONSTANT(SPACINGMODE_LENGTH);
	BIND_ENUM_CONSTANT(SPACINGMODE_FIXED);
	BIND_ENUM_CONSTANT(SPACINGMODE_PERCENT);

	BIND_ENUM_CONSTANT(ROTATEMODE_TANGENT);
	BIND_ENUM_CONSTANT(ROTATEMODE_CHAIN);
	BIND_ENUM_CONSTANT(ROTATEMODE_CHAINSCALE);
}

SpinePathConstraintData::SpinePathConstraintData() {}
SpinePathConstraintData::~SpinePathConstraintData() {}

Array SpinePathConstraintData::get_bones(){
	auto bs = get_spine_data()->getBones();
	Array gd_bs;
	gd_bs.resize(bs.size());
	for(size_t i=0; i < bs.size(); ++i){
		if(bs[i] == NULL) gd_bs[i] = Ref<SpineBoneData>(NULL);
		else {
			Ref<SpineBoneData> gd_b(memnew(SpineBoneData));
			gd_b->set_spine_object(bs[i]);
			gd_bs[i] = gd_b;
		}
	}
	return gd_bs;
}

Ref<SpineSlotData> SpinePathConstraintData::get_target(){
	auto s = get_spine_data()->getTarget();
	if(s == NULL) return NULL;
	Ref<SpineSlotData> gd_s(memnew(SpineSlotData));
	gd_s->set_spine_object(s);
	return gd_s;
}
void SpinePathConstraintData::set_target(Ref<SpineSlotData> v){
	if(v.is_valid()){
		get_spine_data()->setTarget(v->get_spine_object());
	}else{
		get_spine_data()->setTarget(NULL);
	}
}

SpinePathConstraintData::PositionMode SpinePathConstraintData::get_position_mode(){
	auto m = (int) get_spine_data()->getPositionMode();
	return (PositionMode) m;
}
void SpinePathConstraintData::set_position_mode(PositionMode v){
	auto m = (int) v;
	get_spine_data()->setPositionMode((spine::PositionMode)m);
}

SpinePathConstraintData::SpacingMode SpinePathConstraintData::get_spacing_mode(){
	auto m = (int) get_spine_data()->getSpacingMode();
	return (SpacingMode) m;
}
void SpinePathConstraintData::set_spacing_mode(SpacingMode v){
	auto m = (int) v;
	get_spine_data()->setSpacingMode((spine::SpacingMode)m);
}

SpinePathConstraintData::RotateMode SpinePathConstraintData::get_rotate_mode(){
	auto m = (int) get_spine_data()->getRotateMode();
	return (RotateMode) m;
}
void SpinePathConstraintData::set_rotate_mode(RotateMode v){
	auto m = (int) v;
	get_spine_data()->setRotateMode((spine::RotateMode)m);
}

float SpinePathConstraintData::get_offset_rotation(){
	return get_spine_data()->getOffsetRotation();
}
void SpinePathConstraintData::set_offset_rotation(float v){
	get_spine_data()->setOffsetRotation(v);
}

float SpinePathConstraintData::get_position(){
	return get_spine_data()->getPosition();
}
void SpinePathConstraintData::set_position(float v){
	get_spine_data()->setPosition(v);
}

float SpinePathConstraintData::get_spacing(){
	return get_spine_data()->getSpacing();
}
void SpinePathConstraintData::set_spacing(float v){
	get_spine_data()->setSpacing(v);
}

float SpinePathConstraintData::get_rotate_mix(){
	return get_spine_data()->getRotateMix();
}
void SpinePathConstraintData::set_rotate_mix(float v){
	get_spine_data()->setRotateMix(v);
}

float SpinePathConstraintData::get_translate_mix(){
	return get_spine_data()->getTranslateMix();
}
void SpinePathConstraintData::set_translate_mix(float v){
	get_spine_data()->setTranslateMix(v);
}