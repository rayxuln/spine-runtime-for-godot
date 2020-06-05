//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEPATHCONSTRAINT_H
#define GODOT_SPINEPATHCONSTRAINT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpinePathConstraint : public Reference{
	GDCLASS(SpinePathConstraint, Reference);

protected:
	static void _bind_methods();

private:
	spine::PathConstraint *path_constraint;

public:
	SpinePathConstraint();
	~SpinePathConstraint();

	inline void set_spine_object(spine::PathConstraint *pc){
		path_constraint = pc;
	}
	inline spine::PathConstraint *get_spine_object(){
		return path_constraint;
	}
};

#endif //GODOT_SPINEPATHCONSTRAINT_H
