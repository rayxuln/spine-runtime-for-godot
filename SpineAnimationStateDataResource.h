//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINEANIMATIONSTATEDATARESOURCE_H
#define GODOT_SPINEANIMATIONSTATEDATARESOURCE_H

#include "core/variant_parser.h"

#include "SpineSkeletonDataResource.h"

class SpineAnimationStateDataResource : public Resource{
	GDCLASS(SpineAnimationStateDataResource, Resource);

protected:
	static void _bind_methods();

private:
	Ref<SpineSkeletonDataResource> skeleton;

	spine::AnimationStateData *animation_state_data;

	bool animation_state_data_created;

	float default_mix;
public:

	void set_skeleton(const Ref<SpineSkeletonDataResource> &s);
	Ref<SpineSkeletonDataResource> get_skeleton();

	inline spine::AnimationStateData *get_animation_state_data(){
		return animation_state_data;
	}

	void set_default_mix(float m);
	float get_default_mix();

	void set_mix(const String &from, const String &to, float mix_duration);
	float get_mix(const String &from, const String &to);


	void _on_skeleton_data_loaded();
	void _on_skeleton_data_changed();

	bool is_animation_state_data_created();

	SpineAnimationStateDataResource();
	~SpineAnimationStateDataResource();
};

#endif //GODOT_SPINEANIMATIONSTATEDATARESOURCE_H
