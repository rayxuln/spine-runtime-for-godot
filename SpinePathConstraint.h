//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINEPATHCONSTRAINT_H
#define GODOT_SPINEPATHCONSTRAINT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineBone.h"
#include "SpineSlot.h"
#include "SpinePathConstraintData.h"

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

	// The spine-runtime-cpp 4.0 seems to not have a apply function implementation.
	// void apply(); 

	void update();

	int get_order();

	float get_position();
	void set_position(float v);

	float get_spacing();
	void set_spacing(float v);

	float get_rotate_mix();
	void set_rotate_mix(float v);

	float get_translate_mix();
	void set_translate_mix(float v);

	Array get_bones();

	Ref<SpineSlot> get_target();
	void set_target(Ref<SpineSlot> v);

	Ref<SpinePathConstraintData> get_data();

	bool is_active();
	void set_active(bool v);
};

#endif //GODOT_SPINEPATHCONSTRAINT_H
