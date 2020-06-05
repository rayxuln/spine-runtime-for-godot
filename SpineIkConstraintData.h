//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINEIKCONSTRAINTDATA_H
#define GODOT_SPINEIKCONSTRAINTDATA_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineConstraintData.h"
#include "SpineBoneData.h"

class SpineIkConstraintData : public SpineConstraintData {
	GDCLASS(SpineIkConstraintData, SpineConstraintData);

protected:
	static void _bind_methods();

public:
	SpineIkConstraintData();
	~SpineIkConstraintData();

	virtual inline spine::IkConstraintData *get_spine_data(){
		return (spine::IkConstraintData*) SpineConstraintData::get_spine_object();
	}

	Array get_bones();

	Ref<SpineBoneData> get_target();
	void set_target(Ref<SpineBoneData> v);

	int get_bend_direction();
	void set_bend_direction(int v);

	bool get_compress();
	void set_compress(bool v);

	bool get_stretch();
	void set_stretch(bool v);

	bool get_uniform();
	void set_uniform(bool v);

	float get_mix();
	void set_mix(float v);

	float get_softness();
	void set_softness(float v);

};

#endif //GODOT_SPINEIKCONSTRAINTDATA_H
