//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINESPRITE_H
#define GODOT_SPINESPRITE_H

#include <scene/resources/texture.h>
#include <scene/resources/shape_2d.h>
#include <scene/2d/collision_object_2d.h>

#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"
#include "SpineSpriteMeshInstance2D.h"
#include "PackedSpineSkinResource.h"

class SpineSprite : public Node2D, public spine::AnimationStateListenerObject {
    GDCLASS(SpineSprite, Node2D);
protected:
    static void _bind_methods();

	void _notification(int p_what);

	void _build_bounding_box_polygon();
	void _add_shapes_to_parent();

	void _update_in_shape_owner(bool p_xform_only = false);
	
	Vector<Vector<Vector2>> _decompose_in_convex(Vector<Point2> p_polygon);
	void draw_bounding_boxes(Ref<SpineSkeleton> s);
	void _draw_polygon(Vector<Point2> p, Color color, bool one_way_collision);

	virtual void _validate_property(PropertyInfo &property) const;
private:

    Ref<SpineAnimationStateDataResource> animation_state_data_res;

	Ref<SpineSkeleton> skeleton;
	Ref<SpineAnimationState> animation_state;

	Vector<SpineSpriteMeshInstance2D*> mesh_instances;

	Array current_animations;
	int select_track_id;
	float empty_animation_duration;
	Array bind_slot_nodes;
	bool overlap = false;
	Ref<PackedSpineSkinResource> skin;

	spine::SkeletonClipping *skeleton_clipper;

	// Bounding box. Behaves like a CollisionPolygon2D or CollisionShape2D and sets a shape on its parent
	CollisionObject2D *parent;
	String bounding_box_slot_name;
	uint32_t owner_id;
	Ref<Shape2D> shapes;
	Vector<Point2> polygon;
	Color colors;
public:
	SpineSprite();
	~SpineSprite();

    void set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &a);
    Ref<SpineAnimationStateDataResource> get_animation_state_data_res();

	Ref<SpineSkeleton> get_skeleton();
	Ref<SpineAnimationState> get_animation_state();

	void gen_mesh_from_skeleton(Ref<SpineSkeleton> s);
	void remove_mesh_instances();
	void remove_redundant_mesh_instances();

	void update_mesh_from_skeleton(Ref<SpineSkeleton> s);

	void update_bind_slot_nodes();
	void update_bind_slot_node_transform(Ref<SpineBone> bone, Node2D *node2d);
	void update_bind_slot_node_draw_order(const String &slot_name, Node2D *node2d);
	Node *find_child_node_by_node(Node *node);

	virtual void callback(spine::AnimationState* state, spine::EventType type, spine::TrackEntry* entry, spine::Event* event);

	void _on_animation_data_created();
	void _on_animation_data_changed();


	// External feature functions
	Array get_current_animations();
	void set_current_animations(Array as);

	int get_select_track_id();
	void set_select_track_id(int v);

	bool get_clear_track();
	void set_clear_track(bool v);

	bool get_clear_tracks();
	void set_clear_tracks(bool v);

	float get_empty_animation_duration();
	void set_empty_animation_duration(float v);

	bool get_set_empty_animation();
	void set_set_empty_animation(bool v);

	bool get_set_empty_animations();
	void set_set_empty_animations(bool v);

	Array get_bind_slot_nodes();
	void set_bind_slot_nodes(Array v);

	void bind_slot_with_node_2d(const String &slot_name, Node2D *n);
	void unbind_slot_with_node_2d(const String &slot_name, Node2D *n);

	//allow z-manipulation
	bool get_overlap();
	void set_overlap(bool v);

	void set_skin(Ref<PackedSpineSkinResource> v);
	Ref<PackedSpineSkinResource> get_skin();
	void _on_skin_property_changed();
	void update_runtime_skin();

	Ref<SpineSkin> gen_spine_skin_from_packed_resource(Ref<PackedSpineSkinResource> res);

	// Bounding box
	Ref<Shape2D> get_bounding_box(const String& p_slot_name);
	Color get_bounding_box_color(const String& p_slot_name);

	void set_bounding_box_slot_name(const String& p_slot_name);
	String get_bounding_box_slot_name() const;

	void set_bounding_box_attachment_name(const String& p_attachment_name);
	String get_bounding_box_attachment_name() const;
};


#endif //GODOT_SPINESPRITE_H
