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

class SpineSprite : public Node2D, public spine::AnimationStateListenerObject {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

	void _notification(int p_what);
private:
    Ref<SpineAnimationStateDataResource> animation_state_data_res;

	Ref<SpineSkeleton> skeleton;
	Ref<SpineAnimationState> animation_state;

	Vector<MeshInstance2D*> mesh_instances;

	Array current_animations;
	int select_track_id;
	float empty_animation_duration;
public:
	SpineSprite();
	~SpineSprite();

    void set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &a);
    Ref<SpineAnimationStateDataResource> get_animation_state_data_res();

	Ref<SpineSkeleton> get_skeleton();
	Ref<SpineAnimationState> get_animation_state();

	void gen_mesh_from_skeleton(Ref<SpineSkeleton> s);
	void remove_mesh_instances();

	void update_mesh_from_skeleton(Ref<SpineSkeleton> s);

	virtual void callback(spine::AnimationState* state, spine::EventType type, spine::TrackEntry* entry, spine::Event* event);

	void _on_animation_data_created();
	void _on_animation_data_changed();

	// External feature functions
	Array get_current_animations();
	void set_current_animations(Array as);

	int get_select_track_id();
	void set_select_track_id(int v);

	bool get_clear_track();
	void set_clear_track(bool v);

	bool get_clear_tracks();
	void set_clear_tracks(bool v);

	float get_empty_animation_duration();
	void set_empty_animation_duration(float v);

	bool get_set_empty_animation();
	void set_set_empty_animation(bool v);

	bool get_set_empty_animations();
	void set_set_empty_animations(bool v);
};


#endif //GODOT_SPINESPRITE_H
