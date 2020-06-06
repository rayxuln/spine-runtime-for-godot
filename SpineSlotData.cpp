//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineSlotData.h"

void SpineSlotData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_index"), &SpineSlotData::get_index);
	ClassDB::bind_method(D_METHOD("get_slot_name"), &SpineSlotData::get_slot_name);
	ClassDB::bind_method(D_METHOD("get_bone_data"), &SpineSlotData::get_bone_data);
	ClassDB::bind_method(D_METHOD("get_color"), &SpineSlotData::get_color);
	ClassDB::bind_method(D_METHOD("get_dark_color"), &SpineSlotData::get_dark_color);
	ClassDB::bind_method(D_METHOD("has_dark_color"), &SpineSlotData::has_dark_color);
	ClassDB::bind_method(D_METHOD("set_has_dark_color", "v"), &SpineSlotData::set_has_dark_color);
	ClassDB::bind_method(D_METHOD("get_attachment_name"), &SpineSlotData::get_attachment_name);
	ClassDB::bind_method(D_METHOD("set_attachment_name", "v"), &SpineSlotData::set_attachment_name);
	ClassDB::bind_method(D_METHOD("get_blend_mode"), &SpineSlotData::get_blend_mode);
	ClassDB::bind_method(D_METHOD("set_blend_mode", "v"), &SpineSlotData::set_blend_mode);

	ClassDB::bind_method(D_METHOD("set_color", "v"), &SpineSlotData::set_color);
	ClassDB::bind_method(D_METHOD("set_dark_color", "v"), &SpineSlotData::set_dark_color);

	BIND_ENUM_CONSTANT(BLENDMODE_NORMAL);
	BIND_ENUM_CONSTANT(BLENDMODE_ADDITIVE);
	BIND_ENUM_CONSTANT(BLENDMODE_MULTIPLY);
	BIND_ENUM_CONSTANT(BLENDMODE_SCREEN);
}

SpineSlotData::SpineSlotData():slot_data(NULL) {}
SpineSlotData::~SpineSlotData() {}

#define S_T(x) (spine::String(x.utf8()))
int SpineSlotData::get_index(){
	return slot_data->getIndex();
}

String SpineSlotData::get_slot_name(){
	return slot_data->getName().buffer();
}

Ref<SpineBoneData> SpineSlotData::get_bone_data(){
	auto &bd = slot_data->getBoneData();
	Ref<SpineBoneData> gd_bone_data(memnew(SpineBoneData));
	gd_bone_data->set_spine_object(&bd);
	return gd_bone_data;
}

Color SpineSlotData::get_color(){
	auto &c = slot_data->getColor();
	return Color(c.r, c.g, c.b, c.a);
}
void SpineSlotData::set_color(Color v){
	auto &c = slot_data->getColor();
	c.set(v.r, v.g, v.b, v.a);
}

Color SpineSlotData::get_dark_color(){
	auto &c = slot_data->getDarkColor();
	return Color(c.r, c.g, c.b, c.a);
}
void SpineSlotData::set_dark_color(Color v){
	auto &c = slot_data->getDarkColor();
	c.set(v.r, v.g, v.b, v.a);
}

bool SpineSlotData::has_dark_color(){
	return slot_data->hasDarkColor();
}
void SpineSlotData::set_has_dark_color(bool v){
	slot_data->setHasDarkColor(v);
}

String SpineSlotData::get_attachment_name(){
	return slot_data->getAttachmentName().buffer();
}
void SpineSlotData::set_attachment_name(const String &v){
	slot_data->setAttachmentName(S_T(v));
}

SpineSlotData::BlendMode SpineSlotData::get_blend_mode(){
	auto bm = (int) slot_data->getBlendMode();
	return (BlendMode) bm;
}
void SpineSlotData::set_blend_mode(BlendMode v){
	auto bm = (int) v;
	slot_data->setBlendMode((spine::BlendMode) bm);
}

#undef S_T