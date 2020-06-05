//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEIKCONSTRAINT_H
#define GODOT_SPINEIKCONSTRAINT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpineIkConstraint : public Reference {
	GDCLASS(SpineIkConstraint, Reference);

protected:
	static void _bind_methods();

private:
	spine::IkConstraint *ik_constraint;

public:
	SpineIkConstraint();
	~SpineIkConstraint();

	inline void set_spine_object(spine::IkConstraint * ic){
		ik_constraint = ic;
	}
	inline spine::IkConstraint *get_spine_object(){
		return ik_constraint;
	}

};

#endif //GODOT_SPINEIKCONSTRAINT_H
