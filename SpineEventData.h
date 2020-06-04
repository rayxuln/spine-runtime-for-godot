//
// Created by Raymond_Lx on 2020/6/4.
//

#ifndef GODOT_SPINEEVENTDATA_H
#define GODOT_SPINEEVENTDATA_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpineEventData : public Reference{
	GDCLASS(SpineEventData, Reference);

protected:
	static void _bind_methods();
private:
	const spine::EventData *event_data;
public:
	SpineEventData();
	~SpineEventData();

	inline void set_spine_object(const spine::EventData *e){
		event_data = e;
	}
	inline const spine::EventData *get_spine_object(){
		return event_data;
	}
};

#endif //GODOT_SPINEEVENTDATA_H
