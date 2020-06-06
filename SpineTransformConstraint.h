//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINETRANSFORMCONSTRAINT_H
#define GODOT_SPINETRANSFORMCONSTRAINT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineTransformConstraintData.h"
#include "SpineBone.h"

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

	void apply();

	void update();

	int get_order();

	Ref<SpineTransformConstraintData> get_data();

	Array get_bones();

	Ref<SpineBone> get_target();
	void set_target(Ref<SpineBone> v);

	float get_rotate_mix();
	void set_rotate_mix(float v);

	float get_translate_mix();
	void set_translate_mix(float v);

	float get_scale_mix();
	void set_scale_mix(float v);

	float get_shear_mix();
	void set_shear_mix(float v);

	bool is_active();
	void set_active(bool v);
};

#endif //GODOT_SPINETRANSFORMCONSTRAINT_H
