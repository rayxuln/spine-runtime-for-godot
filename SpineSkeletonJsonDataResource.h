//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETONJSONDATARESOURCE_H
#define GODOT_SPINESKELETONJSONDATARESOURCE_H

#include "core/variant_parser.h"

class SpineSkeletonJsonDataResource : public Resource{
	GDCLASS(SpineSkeletonJsonDataResource, Resource);

protected:
	static void _bind_methods();
};

#endif //GODOT_SPINESKELETONJSONDATARESOURCE_H
