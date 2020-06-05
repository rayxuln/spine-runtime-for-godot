//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETON_H
#define GODOT_SPINESKELETON_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineSkeletonDataResource.h"
#include "SpineBone.h"
#include "SpineSlot.h"


class SpineSkeleton : public Reference{
	GDCLASS(SpineSkeleton, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skeleton *skeleton;

public:

	void load_skeleton(Ref<SpineSkeletonDataResource> sd);

	inline void set_spine_object(spine::Skeleton *s){
		skeleton = s;
	}
	inline spine::Skeleton *get_spine_object(){
		return skeleton;
	}

	inline void update_world_transform(){
		skeleton->updateWorldTransform();
	}

	SpineSkeleton();
	~SpineSkeleton();
};

#endif //GODOT_SPINESKELETON_H
