//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineEvent.h"

void SpineEvent::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_data"), &SpineEvent::get_data);
	ClassDB::bind_method(D_METHOD("get_event_name"), &SpineEvent::get_event_name);
	ClassDB::bind_method(D_METHOD("get_time"), &SpineEvent::get_time);
	ClassDB::bind_method(D_METHOD("get_int_value"), &SpineEvent::get_int_value);
	ClassDB::bind_method(D_METHOD("set_int_value", "v"), &SpineEvent::set_int_value);
	ClassDB::bind_method(D_METHOD("get_float_value"), &SpineEvent::get_float_value);
	ClassDB::bind_method(D_METHOD("set_float_value", "v"), &SpineEvent::set_float_value);
	ClassDB::bind_method(D_METHOD("get_string_value"), &SpineEvent::get_string_value);
	ClassDB::bind_method(D_METHOD("set_string_value", "v"), &SpineEvent::set_string_value);
	ClassDB::bind_method(D_METHOD("get_volume"), &SpineEvent::get_volume);
	ClassDB::bind_method(D_METHOD("set_volume", "v"), &SpineEvent::set_volume);
	ClassDB::bind_method(D_METHOD("get_balance"), &SpineEvent::get_balance);
	ClassDB::bind_method(D_METHOD("set_balance", "v"), &SpineEvent::set_balance);
//
//	BIND_ENUM_CONSTANT(EVENTTYPE_START);
//	BIND_ENUM_CONSTANT(EVENTTYPE_INTERRUPT);
//	BIND_ENUM_CONSTANT(EVENTTYPE_END);
//	BIND_ENUM_CONSTANT(EVENTTYPE_COMPLETE);
//	BIND_ENUM_CONSTANT(EVENTTYPE_DISPOSE);
//	BIND_ENUM_CONSTANT(EVENTTYPE_EVENT);
}

SpineEvent::SpineEvent():event(NULL) {}
SpineEvent::~SpineEvent(){}

Ref<SpineEventData> SpineEvent::get_data(){
	Ref<SpineEventData> event_data(memnew(SpineEventData));
	event_data->set_spine_object(&(event->getData()));
	return event_data;
}

String SpineEvent::get_event_name() {
	return event->getData().getName().buffer();
}

float SpineEvent::get_time(){
	return event->getTime();
}

int SpineEvent::get_int_value(){
	return event->getIntValue();
}

void SpineEvent::set_int_value(int v){
	event->setIntValue(v);
}

float SpineEvent::get_float_value(){
	return event->getFloatValue();
}

void SpineEvent::set_float_value(float v){
	event->setFloatValue(v);
}

String SpineEvent::get_string_value(){
	return event->getStringValue().buffer();
}

void SpineEvent::set_string_value(const String &v){
	event->setStringValue(spine::String(v.utf8()));
}

float SpineEvent::get_volume(){
	return event->getVolume();
}

void SpineEvent::set_volume(float v){
	event->setVolume(v);
}

float SpineEvent::get_balance(){
	return event->getBalance();
}

void SpineEvent::set_balance(float v){
	event->setBalance(v);
}