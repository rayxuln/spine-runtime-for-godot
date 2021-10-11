//
// Created by Raymond_Lx on 2020/6/3.
//

#ifndef GODOT_SPINESKELETON_H
#define GODOT_SPINESKELETON_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineSkeletonDataResource.h"
#include "SpineBone.h"
#include "SpineSlot.h"

class SpineSprite;

class SpineSkeleton : public Reference{
	GDCLASS(SpineSkeleton, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skeleton *skeleton;
	bool spine_object;

	SpineSprite *the_sprite;
public:

	SpineSkeleton();
	~SpineSkeleton();

	void load_skeleton(Ref<SpineSkeletonDataResource> sd);

	inline void set_spine_object(spine::Skeleton *s){
		skeleton = s;
		spine_object = true;
	}
	inline spine::Skeleton *get_spine_object(){
		return skeleton;
	}

	void set_spine_sprite(SpineSprite *s);


	void update_world_transform();

	void set_to_setup_pose();

	void set_bones_to_setup_pose();

	void set_slots_to_setup_pose();

	Ref<SpineBone> find_bone(const String &name);
	// int find_bone_index(const String &name);

	Ref<SpineSlot> find_slot(const String &name);
	// int find_slot_index(const String &name);

	void set_skin_by_name(const String &skin_name);
	void set_skin(Ref<SpineSkin> new_skin);

	Ref<SpineAttachment> get_attachment_by_slot_name(const String &slot_name, const String &attachment_name);
	Ref<SpineAttachment> get_attachment_by_slot_index(int slot_index, const String &attachment_name);

	void set_attachment(const String &slot_name, const String &attachment_name);

	Ref<SpineIkConstraint> find_ik_constraint(const String &constraint_name);
	Ref<SpineTransformConstraint> find_transform_constraint(const String &constraint_name);
	Ref<SpinePathConstraint> find_path_constraint(const String &constraint_name);

	void update(float delta);

	Dictionary get_bounds();

	Ref<SpineBone> get_root_bone();

	Ref<SpineSkeletonDataResource> get_data() const;

	Array get_bones();
	Array get_slots();
	Array get_draw_orders();
	Array get_ik_constraints();
	Array get_path_constraints();
	Array get_transform_constraints();

	Ref<SpineSkin> get_skin();

	Color get_color();
	void set_color(Color v);

	float get_time();
	void set_time(float v);

	void set_position(Vector2 pos);

	float get_x();
	void set_x(float v);

	float get_y();
	void set_y(float v);

	float get_scale_x();
	void set_scale_x(float v);

	float get_scale_y();
	void set_scale_y(float v);

};

#endif //GODOT_SPINESKELETON_H
