//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINETRANSFORMCONSTRAINT_H
#define GODOT_SPINETRANSFORMCONSTRAINT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpineTransformConstraint : public Reference{
	GDCLASS(SpineTransformConstraint, Reference);

protected:
	static void _bind_methods();

private:
	spine::TransformConstraint *transform_constraint;

public:
	SpineTransformConstraint();
	~SpineTransformConstraint();

	inline void set_spine_object(spine::TransformConstraint *tc){
		transform_constraint = tc;
	}
	inline spine::TransformConstraint *get_spine_object(){
		return transform_constraint;
	}
};

#endif //GODOT_SPINETRANSFORMCONSTRAINT_H
