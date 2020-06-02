//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSprite.h"



void SpineSprite::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_skeleton_data", "skeleton_data"), &SpineSprite::set_skeleton_data);
    ClassDB::bind_method(D_METHOD("get_skeleton_data"), &SpineSprite::get_skeleton_data);


    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton_data", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineSkeletonDataResource"), "set_skeleton_data", "get_skeleton_data");

}

void SpineSprite::set_skeleton_data(const Ref<SpineSkeletonDataResource> &s) {
    skeleton_data = s;
}
Ref<SpineSkeletonDataResource> SpineSprite::get_skeleton_data() {
    return skeleton_data;
}