//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINETRANSFORMCONSTRAINTDATA_H
#define GODOT_SPINETRANSFORMCONSTRAINTDATA_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineConstraintData.h"
#include "SpineBoneData.h"

class SpineTransformConstraintData : public SpineConstraintData {
	GDCLASS(SpineTransformConstraintData, SpineConstraintData);

protected:
	static void _bind_methods();

public:
	SpineTransformConstraintData();
	~SpineTransformConstraintData();

	virtual inline spine::TransformConstraintData *get_spine_data(){
		return (spine::TransformConstraintData*) SpineConstraintData::get_spine_object();
	}

	Array get_bones();
	Ref<SpineBoneData> get_target();
	float get_mix_rotate();
	float get_mix_x();
	float get_mix_y();
	float get_mix_scale_x();
	float get_mix_scale_y();
	float get_mix_shear_y();

	float get_offset_rotation();
	float get_offset_x();
	float get_offset_y();
	float get_offset_scale_x();
	float get_offset_scale_y();
	float get_offset_shear_y();

	bool is_relative();
	bool is_local();
};

#endif //GODOT_SPINETRANSFORMCONSTRAINTDATA_H
