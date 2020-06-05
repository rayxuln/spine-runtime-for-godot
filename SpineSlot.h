//
// Created by Raymond_Lx on 2020/6/6.
//

#ifndef GODOT_SPINESLOT_H
#define GODOT_SPINESLOT_H

#include "core/variant_parser.h"

#include <spine/spine.h>

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
};

#endif //GODOT_SPINESLOT_H
