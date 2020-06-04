//
// Created by Raymond_Lx on 2020/6/4.
//

#ifndef GODOT_SPINETRACKENTRY_H
#define GODOT_SPINETRACKENTRY_H

#include "core/variant_parser.h"

#include <spine/spine.h>

class SpineTrackEntry : public Reference{
	GDCLASS(SpineTrackEntry, Reference);

protected:
	static void _bind_methods();

private:
	spine::TrackEntry *track_entry;

public:
	SpineTrackEntry();
	~SpineTrackEntry();

	inline void set_spine_object(spine::TrackEntry *t){
		track_entry = t;
	}
	inline spine::TrackEntry *get_spine_object(){
		return track_entry;
	}
};

#endif //GODOT_SPINETRACKENTRY_H
