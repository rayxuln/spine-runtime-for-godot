//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEBONEDATA_H
#define GODOT_SPINEBONEDATA_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpineBoneData : public Reference {
	GDCLASS(SpineBoneData, Reference);

protected:
	static void _bind_methods();

private:
	spine::BoneData *bone_data;

public:
	SpineBoneData();
	~SpineBoneData();

	inline void set_spine_object(spine::BoneData *b){
		bone_data = b;
	}
	inline spine::BoneData *get_spine_object(){
		return bone_data;
	}

	enum TransformMode {
		TRANSFORMMODE_NORMAL = 0,
		TRANSFORMMODE_ONLYTRANSLATION,
		TRANSFORMMODE_NOROTATIONORREFLECTION,
		TRANSFORMMODE_NOSCALE,
		TRANSFORMMODE_NOSCALEORREFLECTION
	};

	int get_index();

	String get_bone_name();

	Ref<SpineBoneData> get_parent();

	float get_length();
	void set_length(float v);

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_rotation();
	void set_rotation(float v);

	float get_scale_x();
	void set_scale_x(float v);

	float get_scale_y();
	void set_scale_y(float v);

	float get_shear_x();
	void set_shear_x(float v);

	float get_shear_y();
	void set_shear_y(float v);

	TransformMode get_transform_mode();
	void set_transform_mode(TransformMode v);

	bool is_skin_required();
	void set_skin_required(bool v);

};

VARIANT_ENUM_CAST(SpineBoneData::TransformMode);
#endif //GODOT_SPINEBONEDATA_H
