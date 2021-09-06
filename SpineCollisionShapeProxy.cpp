//
// Created by Raiix on 2021/7/15.
//

#include "SpineCollisionShapeProxy.h"

#include "SpineSprite.h"

void SpineCollisionShapeProxy::_bind_methods() {
    ClassDB::bind_method(D_METHOD("get_spine_sprite_path"), &SpineCollisionShapeProxy::get_spine_sprite_path);
    ClassDB::bind_method(D_METHOD("set_spine_sprite_path", "v"), &SpineCollisionShapeProxy::set_spine_sprite_path);

    ClassDB::bind_method(D_METHOD("get_slot"), &SpineCollisionShapeProxy::get_slot);
    ClassDB::bind_method(D_METHOD("set_slot", "v"), &SpineCollisionShapeProxy::set_slot);

    ClassDB::bind_method(D_METHOD("get_sync_transform"), &SpineCollisionShapeProxy::get_sync_transform);
    ClassDB::bind_method(D_METHOD("set_sync_transform", "v"), &SpineCollisionShapeProxy::set_sync_transform);

    ADD_PROPERTY(PropertyInfo(Variant::NODE_PATH, "spine_sprite_path"), "set_spine_sprite_path", "get_spine_sprite_path");
    ADD_PROPERTY(PropertyInfo(Variant::BOOL, "sync_transform"), "set_sync_transform", "get_sync_transform");
}

SpineCollisionShapeProxy::SpineCollisionShapeProxy():sync_transform(true) {

}

SpineCollisionShapeProxy::~SpineCollisionShapeProxy() {

}

void SpineCollisionShapeProxy::_notification(int p_what) {
    switch (p_what) {
        case NOTIFICATION_READY: {
            set_process_internal(true);
        } break;
        case NOTIFICATION_INTERNAL_PROCESS: {
            if (!disabled) {
                if (sync_transform) _sync_transform(get_spine_sprite());
                _update_polygon_from_spine_sprite(get_spine_sprite());
                if (is_visible()) update();
            }
        } break;
    }
}

SpineSprite *SpineCollisionShapeProxy::get_spine_sprite() const {
    return (SpineSprite*) get_node_or_null(spine_sprite_path);
}

NodePath SpineCollisionShapeProxy::get_spine_sprite_path() {
    return spine_sprite_path;
}

void SpineCollisionShapeProxy::set_spine_sprite_path(NodePath v) {
    spine_sprite_path = v;

    _update_polygon_from_spine_sprite(get_spine_sprite());
}

String SpineCollisionShapeProxy::get_slot() const {
    return slot;
}

void SpineCollisionShapeProxy::set_slot(const String &v) {
    slot = v;
    _update_polygon_from_spine_sprite(get_spine_sprite());
}

void SpineCollisionShapeProxy::_update_polygon_from_spine_sprite(SpineSprite *sprite) {
    _clear_polygon();
    if (sprite == nullptr || slot.empty()) {
        return;
    }

    if (!sprite->get_skeleton().is_valid()) {
        return;
    }

    auto sk = sprite->get_skeleton()->get_spine_object();

    spine::Vector<float> vertices;

    spine::Slot *s = sk->findSlot(spine::String(slot.utf8()));
    if (!s) {
        return;
    }
    spine::Attachment *attachment = s->getAttachment();
    if(!attachment){
        return;
    }

    if (attachment->getRTTI().isExactly(spine::BoundingBoxAttachment::rtti)) {
        auto *box = (spine::BoundingBoxAttachment*) attachment;

        vertices.setSize(box->getWorldVerticesLength(), 0);
        box->computeWorldVertices(*s, vertices);
    } else {
        return;
    }

    polygon.resize(vertices.size()/2);
    for (size_t j=0; j < vertices.size(); j+=2) {
        polygon.set(j/2, Vector2(vertices[j], -vertices[j + 1]));
    }

    set_polygon(polygon);
}

void SpineCollisionShapeProxy::_clear_polygon() {
    polygon.clear();
    set_polygon(polygon);
}

void SpineCollisionShapeProxy::_sync_transform(SpineSprite *sprite) {
    if (sprite == nullptr) return;
    set_global_transform(sprite->get_global_transform());
}

bool SpineCollisionShapeProxy::get_sync_transform() {
    return sync_transform;
}

void SpineCollisionShapeProxy::set_sync_transform(bool v) {
    sync_transform = v;
}

void SpineCollisionShapeProxy::_get_property_list(List<PropertyInfo> *p_list) const {
    PropertyInfo p;
    Vector<String> res;

    p.name = "slot";
    p.type = Variant::STRING;
    _get_slot_list(res);
    if (res.empty()) res.push_back("No Slot");
    p.hint_string = String(",").join(res);
    p.hint = PROPERTY_HINT_ENUM;
    p_list->push_back(p);
}

bool SpineCollisionShapeProxy::_get(const StringName &p_property, Variant &r_value) const {
    if (p_property == "slot") {
        r_value = get_slot();
        return true;
    }
    return false;
}

bool SpineCollisionShapeProxy::_set(const StringName &p_property, const Variant &p_value) {
    if (p_property == "slot") {
        set_slot(p_value);
        return true;
    }
    return false;
}

void SpineCollisionShapeProxy::_get_slot_list(Vector<String> &res) const {
    if (get_spine_sprite() == nullptr) {
        return;
    }

    auto sprite = get_spine_sprite();
    if (!sprite->get_skeleton().is_valid()) {
        return;
    }

    auto slots = sprite->get_skeleton()->get_slots();
    res.resize(slots.size());
    for (size_t i=0; i < res.size(); ++i) {
        auto slot = (Ref<SpineSlot>)slots[i];
        if (slot.is_valid())
            res.set(i, slot->get_data()->get_slot_name());
    }
}






