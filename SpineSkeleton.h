//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETON_H
#define GODOT_SPINESKELETON_H

#include "core/variant_parser.h"

#include "SpineSkeletonDataResource.h"

#include <spine/spine.h>

class SpineSkeleton : public Reference{
	GDCLASS(SpineSkeleton, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skeleton *skeleton;

public:

	void load_skeleton(Ref<SpineSkeletonDataResource> sd);

	inline spine::Skeleton *get_skeleton(){
		return skeleton;
	}

	SpineSkeleton();
	~SpineSkeleton();
};

#endif //GODOT_SPINESKELETON_H
