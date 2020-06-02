//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <scene/2d/node_2d.h>
#include <scene/resources/texture.h>

#include "SpineAtlasResource.h"

class SpineSprite : public Node2D {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

private:
    Ref<SpineAtlasResource> atlas;

    void load_spine_atlas();
public:
    void set_atlas(const Ref<SpineAtlasResource> &a);
    Ref<SpineAtlasResource> get_atlas();
};


#endif //GODOT_SPINESPRITE_H
