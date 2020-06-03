//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <scene/2d/node_2d.h>
#include <scene/resources/texture.h>

#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"

class SpineSprite : public Node2D {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

private:
    Ref<SpineAnimationStateDataResource> animation_state_data_res;

	Ref<SpineSkeleton> skeleton;
	Ref<SpineAnimationState> animation_state;
public:
    void set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &a);
    Ref<SpineAnimationStateDataResource> get_animation_state_data_res();

	void _on_animation_data_created();
};


#endif //GODOT_SPINESPRITE_H
