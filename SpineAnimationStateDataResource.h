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
public:

	void set_skeleton(const Ref<SpineSkeletonDataResource> &s);
	Ref<SpineSkeletonDataResource> get_skeleton();

	void _on_skeleton_data_loaded();

	SpineAnimationStateDataResource();
	~SpineAnimationStateDataResource();
};

#endif //GODOT_SPINEANIMATIONSTATEDATARESOURCE_H
