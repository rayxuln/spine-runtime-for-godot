//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSprite.h"



void SpineSprite::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_atlas", "atlas"), &SpineSprite::set_atlas);
    ClassDB::bind_method(D_METHOD("get_atlas"), &SpineSprite::get_atlas);


    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "atlas", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAtlasResource"), "set_atlas", "get_atlas");

}

void SpineSprite::set_atlas(const Ref<SpineAtlasResource> &a) {
    atlas = a;
}
Ref<SpineAtlasResource> SpineSprite::get_atlas() {
    return atlas;
}

void SpineSprite::load_spine_atlas() {

}