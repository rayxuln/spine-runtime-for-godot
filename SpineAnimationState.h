//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINEANIMATIONSTATE_H
#define GODOT_SPINEANIMATIONSTATE_H

#include "core/variant_parser.h"

#include "SpineAnimationStateDataResource.h"

class SpineAnimationState : public Reference{
	GDCLASS(SpineAnimationState, Reference);

protected:
	static void _bind_methods();

private:
	spine::AnimationState *animation_state;

public:
	void load_animation_state(Ref<SpineAnimationStateDataResource> ad);

	inline spine::AnimationState *get_animation_state(){
		return animation_state;
	}

	SpineAnimationState();
	~SpineAnimationState();
};

#endif //GODOT_SPINEANIMATIONSTATE_H
