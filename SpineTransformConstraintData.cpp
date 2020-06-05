//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineTransformConstraintData.h"

void SpineTransformConstraintData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_all_bone_data"), &SpineTransformConstraintData::get_bones);
	ClassDB::bind_method(D_METHOD("get_target"), &SpineTransformConstraintData::get_target);
	ClassDB::bind_method(D_METHOD("get_rotate_mix"), &SpineTransformConstraintData::get_rotate_mix);
	ClassDB::bind_method(D_METHOD("get_translate_mix"), &SpineTransformConstraintData::get_translate_mix);
	ClassDB::bind_method(D_METHOD("get_scale_mix"), &SpineTransformConstraintData::get_scale_mix);
	ClassDB::bind_method(D_METHOD("get_shear_mix"), &SpineTransformConstraintData::get_shear_mix);
	ClassDB::bind_method(D_METHOD("get_offset_rotation"), &SpineTransformConstraintData::get_offset_rotation);
	ClassDB::bind_method(D_METHOD("get_offset_x"), &SpineTransformConstraintData::get_offset_x);
	ClassDB::bind_method(D_METHOD("get_offset_y"), &SpineTransformConstraintData::get_offset_y);
	ClassDB::bind_method(D_METHOD("get_offset_scale_x"), &SpineTransformConstraintData::get_offset_scale_x);
	ClassDB::bind_method(D_METHOD("get_offset_scale_y"), &SpineTransformConstraintData::get_offset_scale_y);
	ClassDB::bind_method(D_METHOD("get_offset_shear_y"), &SpineTransformConstraintData::get_offset_shear_y);
	ClassDB::bind_method(D_METHOD("is_relative"), &SpineTransformConstraintData::is_relative);
	ClassDB::bind_method(D_METHOD("is_local"), &SpineTransformConstraintData::is_local);
}

SpineTransformConstraintData::SpineTransformConstraintData() {}
SpineTransformConstraintData::~SpineTransformConstraintData() {}

Array SpineTransformConstraintData::get_bones(){
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
Ref<SpineBoneData> SpineTransformConstraintData::get_target(){
	auto b = get_spine_data()->getTarget();
	if(b == NULL) return NULL;
	Ref<SpineBoneData> gd_b(memnew(SpineBoneData));
	gd_b->set_spine_object(b);
	return gd_b;
}
float SpineTransformConstraintData::get_rotate_mix(){
	return get_spine_data()->getRotateMix();
}
float SpineTransformConstraintData::get_translate_mix(){
	return get_spine_data()->getTranslateMix();
}
float SpineTransformConstraintData::get_scale_mix(){
	return get_spine_data()->getScaleMix();
}
float SpineTransformConstraintData::get_shear_mix(){
	return get_spine_data()->getShearMix();
}

float SpineTransformConstraintData::get_offset_rotation(){
	return get_spine_data()->getOffsetRotation();
}
float SpineTransformConstraintData::get_offset_x(){
	return get_spine_data()->getOffsetX();
}
float SpineTransformConstraintData::get_offset_y(){
	return get_spine_data()->getOffsetY();
}
float SpineTransformConstraintData::get_offset_scale_x(){
	return get_spine_data()->getOffsetScaleX();
}
float SpineTransformConstraintData::get_offset_scale_y(){
	return get_spine_data()->getOffsetScaleY();
}
float SpineTransformConstraintData::get_offset_shear_y(){
	return get_spine_data()->getOffsetShearY();
}

bool SpineTransformConstraintData::is_relative(){
	return get_spine_data()->isRelative();
}
bool SpineTransformConstraintData::is_local(){
	return get_spine_data()->isLocal();
}