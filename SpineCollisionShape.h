//
// Created by Raiix on 2021/7/14.
//

#ifndef GODOT_SPINECOLLISIONSHAPE_H
#define GODOT_SPINECOLLISIONSHAPE_H

#include "scene/2d/collision_polygon_2d.h"

class SpineCollisionShape : public CollisionPolygon2D{
    GDCLASS(SpineCollisionShape, CollisionPolygon2D);
protected:
    static void _bind_methods();

public:
    SpineCollisionShape();
    ~SpineCollisionShape();
};


#endif //GODOT_SPINECOLLISIONSHAPE_H
