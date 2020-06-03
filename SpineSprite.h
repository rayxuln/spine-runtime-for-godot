//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <scene/2d/mesh_instance_2d.h>
#include <scene/resources/texture.h>

#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"

class SpineSprite : public Node2D {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

	void _notification(int p_what);
private:
    Ref<SpineAnimationStateDataResource> animation_state_data_res;

	Ref<SpineSkeleton> skeleton;
	Ref<SpineAnimationState> animation_state;

	Vector<MeshInstance2D*> mesh_instances;
public:
    void set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &a);
    Ref<SpineAnimationStateDataResource> get_animation_state_data_res();

	Ref<SpineSkeleton> get_skeleton();
	Ref<SpineAnimationState> get_animation_state();

	void gen_mesh_from_skeleton(Ref<SpineSkeleton> s);
	void remove_mesh_instances();

	void update_mesh_from_skeleton(Ref<SpineSkeleton> s);

	void _on_animation_data_created();
	void _on_animation_data_changed();
};


#endif //GODOT_SPINESPRITE_H
