//
// Created by Raiix on 2020/7/12.
//

#include "PackedSpineSkinResource.h"

void PackedSpineSkinResource::_bind_methods(){
	ClassDB::bind_method(D_METHOD("set_skin_name", "v"), &PackedSpineSkinResource::set_skin_name);
	ClassDB::bind_method(D_METHOD("get_skin_name"), &PackedSpineSkinResource::get_skin_name);
	ClassDB::bind_method(D_METHOD("set_sub_skin_names", "v"), &PackedSpineSkinResource::set_sub_skin_names);
	ClassDB::bind_method(D_METHOD("get_sub_skin_names"), &PackedSpineSkinResource::get_sub_skin_names);

	ADD_SIGNAL(MethodInfo("property_changed"));

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "skin_name"), "set_skin_name", "get_skin_name");
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "sub_skin_names"), "set_sub_skin_names", "get_sub_skin_names");
}

PackedSpineSkinResource::PackedSpineSkinResource():skin_name("custom_skin_name"){}
PackedSpineSkinResource::~PackedSpineSkinResource(){}

void PackedSpineSkinResource::set_skin_name(const String &v){
	skin_name = v;
	emit_signal("property_changed");
}
String PackedSpineSkinResource::get_skin_name(){
	return skin_name;
}

void PackedSpineSkinResource::set_sub_skin_names(Array v){
	sub_skin_names = v;
	emit_signal("property_changed");
}
Array PackedSpineSkinResource::get_sub_skin_names(){
	return sub_skin_names;
}
