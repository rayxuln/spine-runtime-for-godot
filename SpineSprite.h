//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <scene/2d/node_2d.h>
#include <scene/resources/texture.h>

#include "SpineSkeletonDataResource.h"

class SpineSprite : public Node2D {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

private:
    Ref<SpineSkeletonDataResource> skeleton_data;
public:
    void set_skeleton_data(const Ref<SpineSkeletonDataResource> &s);
    Ref<SpineSkeletonDataResource> get_skeleton_data();
};


#endif //GODOT_SPINESPRITE_H
