//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESKELETONDATARESOURCE_H
#define GODOT_SPINESKELETONDATARESOURCE_H

#include "core/variant_parser.h"

#include "SpineAtlasResource.h"

#include <spine/spine.h>

class SpineSkeletonDataResource : public Resource{
	GDCLASS(SpineSkeletonDataResource, Resource);

protected:
	static void _bind_methods();

private:
	Ref<SpineAtlasResource> atlas;
	bool valid;

	spine::SkeletonData *skeleton_data;
public:
	Error load_file(const String &path);

	void load_res(spine::Atlas *a);

	SpineSkeletonDataResource();
	virtual ~SpineSkeletonDataResource();

	void set_atlas(const Ref<SpineAtlasResource> &a);
	Ref<SpineAtlasResource> get_atlas();

	bool is_valid();
};

#endif //GODOT_SPINESKELETONDATARESOURCE_H
