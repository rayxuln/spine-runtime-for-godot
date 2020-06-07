//
// Created by Raymond_Lx on 2020/6/7.
//

#include "SpineSpriteMeshInstance2D.h"

#include "SpineBone.h"

void SpineSpriteMeshInstance2D::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_slot"), &SpineSpriteMeshInstance2D::get_slot);
	ClassDB::bind_method(D_METHOD("apply_transform_2d", "node2d"), &SpineSpriteMeshInstance2D::apply_transform_2d);
}

SpineSpriteMeshInstance2D::SpineSpriteMeshInstance2D() {}
SpineSpriteMeshInstance2D::~SpineSpriteMeshInstance2D() {}

Ref<SpineSlot> SpineSpriteMeshInstance2D::get_slot() {
	return slot;
}

void SpineSpriteMeshInstance2D::apply_transform_2d(Variant o){
	slot->get_bone()->apply_world_transform_2d(o);
}