//
// Created by Raymond_Lx on 2020/6/7.
//

#ifndef GODOT_SPINESPRITEMESHINSTANCE2D_H
#define GODOT_SPINESPRITEMESHINSTANCE2D_H

#include <scene/2d/mesh_instance_2d.h>

#include "SpineSlot.h"

class SpineSpriteMeshInstance2D : public MeshInstance2D {
	GDCLASS(SpineSpriteMeshInstance2D, MeshInstance2D);

protected:
	static void _bind_methods();

	Ref<SpineSlot> slot;
public:
	SpineSpriteMeshInstance2D();
	~SpineSpriteMeshInstance2D();

	inline void set_slot(Ref<SpineSlot> s){
		slot = s;
	}
	Ref<SpineSlot> get_slot();

	void apply_transform_2d(Variant o);
};

#endif //GODOT_SPINESPRITEMESHINSTANCE2D_H
