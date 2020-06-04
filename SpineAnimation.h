//
// Created by Raymond_Lx on 2020/6/4.
//
// This class is for wrapping spine classes and providing some api to access spine api

#ifndef GODOT_SPINEANIMATION_H
#define GODOT_SPINEANIMATION_H

#include "core/variant_parser.h"

#include <spine/spine.h>

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
};

#endif //GODOT_SPINEANIMATION_H
