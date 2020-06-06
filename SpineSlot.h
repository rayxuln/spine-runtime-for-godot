//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINESLOT_H
#define GODOT_SPINESLOT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineSlotData.h"
#include "SpineAttachment.h"

class SpineSkeleton;

class SpineBone;

class SpineSlot : public Reference{
	GDCLASS(SpineSlot, Reference);

protected:
	static void _bind_methods();

private:
	spine::Slot *slot;

public:
	SpineSlot();
	~SpineSlot();

	inline void set_spine_object(spine::Slot *s){
		slot = s;
	}
	inline spine::Slot *get_spine_object(){
		return slot;
	}

	void set_to_setup_pos();

	Ref<SpineSlotData> get_data();

	Ref<SpineBone> get_bone();

	Ref<SpineSkeleton> get_skeleton();

	Color get_color();
	void set_color(Color v);

	Color get_dark_color();
	void set_dark_color(Color v);

	bool has_dark_color();

	Ref<SpineAttachment> get_attachment();
	void set_attachment(Ref<SpineAttachment> v);

	int get_attachment_state();
	void set_attachment_state(int v);

	float get_attachment_time();
	void set_attachment_time(float v);

	Array get_deform();
	void set_deform(Array v);
};

#endif //GODOT_SPINESLOT_H
