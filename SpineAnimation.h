//
// Created by Raymond_Lx on 2020/6/4.
//
// This class is for wrapping spine classes and providing some api to access spine api

#ifndef GODOT_SPINEANIMATION_H
#define GODOT_SPINEANIMATION_H

#include "core/variant_parser.h"

#include "SpineConstant.h"

#include <spine/spine.h>

class SpineEvent;
class SpineSkeleton;
class SpineTimeline;

class SpineAnimation : public Reference{
	GDCLASS(SpineAnimation, Reference);

private:
	spine::Animation *animation;

protected:
	static void _bind_methods();

public:
	SpineAnimation();
	~SpineAnimation();

	inline void set_spine_object(spine::Animation *a){
		animation = a;
	}
	inline spine::Animation *get_spine_object(){
		return animation;
	}

	// Vector<Ref<SpineEvent>> pEvents
    void apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, bool loop, Array pEvents, float alpha, SpineConstant::MixBlend blend, SpineConstant::MixDirection direction);

    Array get_timelines(); // Vector<Ref<SpineTimeline>>
    bool has_timeline(Array ids); // Vector<SpineConstant::PropertyId>

	String get_anim_name();
	float get_duration();
	void set_duration(float v);
};

#endif //GODOT_SPINEANIMATION_H
