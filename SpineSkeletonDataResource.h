//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESKELETONDATARESOURCE_H
#define GODOT_SPINESKELETONDATARESOURCE_H

#include "core/variant_parser.h"

#include "SpineAtlasResource.h"
#include "SpineSkeletonJsonDataResource.h"

#include <spine/spine.h>

class SpineSkeletonDataResource : public Resource{
	GDCLASS(SpineSkeletonDataResource, Resource);

protected:
	static void _bind_methods();

private:
	Ref<SpineAtlasResource> atlas_res;
	Ref<SpineSkeletonJsonDataResource> skeleton_json_res;
	bool valid;

	spine::SkeletonData *skeleton_data;

	void update_skeleton_data();
public:

	void load_res(spine::Atlas *a, const String &json_path);

	SpineSkeletonDataResource();
	virtual ~SpineSkeletonDataResource();

	void set_atlas_res(const Ref<SpineAtlasResource> &a);
	Ref<SpineAtlasResource> get_atlas_res();

	void set_skeleton_json_res(const Ref<SpineSkeletonJsonDataResource> &s);
	Ref<SpineSkeletonJsonDataResource> get_skeleton_json_res();

	inline spine::SkeletonData *get_skeleton_data(){return skeleton_data;}

	bool is_skeleton_data_loaded();
};

#endif //GODOT_SPINESKELETONDATARESOURCE_H
