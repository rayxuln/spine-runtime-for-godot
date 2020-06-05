//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineConstraintData.h"

void SpineConstraintData::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_constraint_data_name"), &SpineConstraintData::get_constraint_data_name);
	ClassDB::bind_method(D_METHOD("get_order"), &SpineConstraintData::get_order);
	ClassDB::bind_method(D_METHOD("set_order", "v"), &SpineConstraintData::set_order);
	ClassDB::bind_method(D_METHOD("is_skin_required"), &SpineConstraintData::is_skin_required);
	ClassDB::bind_method(D_METHOD("set_skin_required", "v"), &SpineConstraintData::set_skin_required);
}

SpineConstraintData::SpineConstraintData():constraint_data(NULL) {}
SpineConstraintData::~SpineConstraintData() {}

String SpineConstraintData::get_constraint_data_name(){
	return constraint_data->getName().buffer();
}

uint64_t SpineConstraintData::get_order(){
	return constraint_data->getOrder();
}
void SpineConstraintData::set_order(uint64_t v){
	constraint_data->setOrder(v);
}

bool SpineConstraintData::is_skin_required(){
	return constraint_data->isSkinRequired();
}
void SpineConstraintData::set_skin_required(bool v){
	constraint_data->setSkinRequired(v);
}