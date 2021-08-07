//
// Created by Raiix on 2021/7/15.
//

#ifndef GODOT_SPINECOLLISIONSHAPEPROXY_H
#define GODOT_SPINECOLLISIONSHAPEPROXY_H

#include "scene/2d/collision_polygon_2d.h"

class SpineSprite;
class SpineAnimationState;
class SpineSkeleton;

class SpineCollisionShapeProxy : public CollisionPolygon2D{
    GDCLASS(SpineCollisionShapeProxy, CollisionPolygon2D)
protected:
    static void _bind_methods();

    NodePath spine_sprite_path;

    String slot;

    bool sync_transform;
protected:
    void _notification(int p_what);
    void _get_property_list(List<PropertyInfo> *p_list) const;
    bool _get(const StringName &p_property, Variant &r_value) const;
    bool _set(const StringName &p_property, const Variant &p_value);


    SpineSprite *get_spine_sprite() const;

    void _update_polygon_from_spine_sprite(SpineSprite *sprite);
    void _clear_polygon();
    void _sync_transform(SpineSprite *sprite);

    void _get_slot_list(Vector<String> &res) const;
public:
    SpineCollisionShapeProxy();
    ~SpineCollisionShapeProxy();

    NodePath get_spine_sprite_path();
    void set_spine_sprite_path(NodePath v);

    String get_slot() const;
    void set_slot(const String &v);

    bool get_sync_transform();
    void set_sync_transform(bool v);
};


#endif //GODOT_SPINECOLLISIONSHAPEPROXY_H
