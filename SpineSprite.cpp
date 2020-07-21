//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSprite.h"

#include "SpineTrackEntry.h"
#include "SpineEvent.h"

void SpineSprite::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_animation_state_data_res", "animation_state_data_res"), &SpineSprite::set_animation_state_data_res);
    ClassDB::bind_method(D_METHOD("get_animation_state_data_res"), &SpineSprite::get_animation_state_data_res);
	ClassDB::bind_method(D_METHOD("_on_animation_data_created"), &SpineSprite::_on_animation_data_created);
	ClassDB::bind_method(D_METHOD("get_skeleton"), &SpineSprite::get_skeleton);
	ClassDB::bind_method(D_METHOD("get_animation_state"), &SpineSprite::get_animation_state);
	ClassDB::bind_method(D_METHOD("_on_animation_data_changed"), &SpineSprite::_on_animation_data_changed);

	ClassDB::bind_method(D_METHOD("get_current_animations"), &SpineSprite::get_current_animations);
	ClassDB::bind_method(D_METHOD("set_current_animations", "current_animations"), &SpineSprite::set_current_animations);

	ClassDB::bind_method(D_METHOD("get_select_track_id"), &SpineSprite::get_select_track_id);
	ClassDB::bind_method(D_METHOD("set_select_track_id", "track_id"), &SpineSprite::set_select_track_id);
	ClassDB::bind_method(D_METHOD("get_clear_track"), &SpineSprite::get_clear_track);
	ClassDB::bind_method(D_METHOD("set_clear_track", "v"), &SpineSprite::set_clear_track);
	ClassDB::bind_method(D_METHOD("get_clear_tracks"), &SpineSprite::get_clear_tracks);
	ClassDB::bind_method(D_METHOD("set_clear_tracks", "v"), &SpineSprite::set_clear_tracks);

	ClassDB::bind_method(D_METHOD("get_empty_animation_duration"), &SpineSprite::get_empty_animation_duration);
	ClassDB::bind_method(D_METHOD("set_empty_animation_duration", "track_id"), &SpineSprite::set_empty_animation_duration);
	ClassDB::bind_method(D_METHOD("get_set_empty_animation"), &SpineSprite::get_set_empty_animation);
	ClassDB::bind_method(D_METHOD("set_set_empty_animation", "v"), &SpineSprite::set_set_empty_animation);
	ClassDB::bind_method(D_METHOD("get_set_empty_animations"), &SpineSprite::get_set_empty_animations);
	ClassDB::bind_method(D_METHOD("set_set_empty_animations", "v"), &SpineSprite::set_set_empty_animations);

	ClassDB::bind_method(D_METHOD("get_bind_slot_nodes"), &SpineSprite::get_bind_slot_nodes);
	ClassDB::bind_method(D_METHOD("set_bind_slot_nodes", "v"), &SpineSprite::set_bind_slot_nodes);
	ClassDB::bind_method(D_METHOD("get_overlap"), &SpineSprite::get_overlap);
	ClassDB::bind_method(D_METHOD("set_overlap", "v"), &SpineSprite::set_overlap);	
	ClassDB::bind_method(D_METHOD("set_skin", "v"), &SpineSprite::set_skin);
	ClassDB::bind_method(D_METHOD("get_skin"), &SpineSprite::get_skin);
	ClassDB::bind_method(D_METHOD("_on_skin_property_changed"), &SpineSprite::_on_skin_property_changed);
	ClassDB::bind_method(D_METHOD("gen_spine_skin_from_packed_resource", "res"), &SpineSprite::gen_spine_skin_from_packed_resource);


	ADD_SIGNAL(MethodInfo("animation_state_ready", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "skeleton", PROPERTY_HINT_TYPE_STRING, "SpineSkeleton")));
	ADD_SIGNAL(MethodInfo("animation_start", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));
	ADD_SIGNAL(MethodInfo("animation_interrupt", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));
	ADD_SIGNAL(MethodInfo("animation_end", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));
	ADD_SIGNAL(MethodInfo("animation_complete", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));
	ADD_SIGNAL(MethodInfo("animation_dispose", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));
	ADD_SIGNAL(MethodInfo("animation_event", PropertyInfo(Variant::OBJECT, "animation_state", PROPERTY_HINT_TYPE_STRING, "SpineAnimationState"), PropertyInfo(Variant::OBJECT, "track_entry", PROPERTY_HINT_TYPE_STRING, "SpineTrackEntry"), PropertyInfo(Variant::OBJECT, "event", PROPERTY_HINT_TYPE_STRING, "SpineEvent")));

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "animation_state_data_res", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAnimationStateDataResource"), "set_animation_state_data_res", "get_animation_state_data_res");

	ADD_PROPERTY(PropertyInfo(Variant::INT, "select_track_id"), "set_select_track_id", "get_select_track_id");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "clear_track_trigger"), "set_clear_track", "get_clear_track");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "clear_tracks_trigger"), "set_clear_tracks", "get_clear_tracks");

	ADD_PROPERTY(PropertyInfo(Variant::REAL, "empty_animation_duration"), "set_empty_animation_duration", "get_empty_animation_duration");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "set_empty_animation_trigger"), "set_set_empty_animation", "get_set_empty_animation");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "set_empty_animations_trigger"), "set_set_empty_animations", "get_set_empty_animations");

	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "current_animations"), "set_current_animations", "get_current_animations");
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "bind_slot_nodes"), "set_bind_slot_nodes", "get_bind_slot_nodes");
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "overlap"), "set_overlap", "get_overlap");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "packed_skin_resource", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "PackedSpineSkinResource"), "set_skin", "get_skin");
}

SpineSprite::SpineSprite() :
		select_track_id(0), empty_animation_duration(0.2f), skeleton_clipper(NULL) {
	skeleton_clipper = new spine::SkeletonClipping();
}
SpineSprite::~SpineSprite() {
	delete skeleton_clipper;
}

void SpineSprite::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY:{
			set_process_internal(true);
			remove_redundant_mesh_instances();
		} break;
		case NOTIFICATION_INTERNAL_PROCESS: {
			if (!(skeleton.is_valid() && animation_state.is_valid()) || mesh_instances.size() == 0)
				return;

			animation_state->update(get_process_delta_time());
			if (!is_visible_in_tree())
				return;
				
			animation_state->apply(skeleton);

			skeleton->update_world_transform();

			update_mesh_from_skeleton(skeleton);

			update();

			update_bind_slot_nodes();
		} break;
	}
}

void SpineSprite::update_bind_slot_nodes(){
	if(animation_state.is_valid() && skeleton.is_valid()){
		for(size_t i=0, n=bind_slot_nodes.size(); i<n; ++i){
			auto a = bind_slot_nodes[i];
			if(a.get_type() == Variant::DICTIONARY){
				auto d = (Dictionary) a;
				if(d.has("slot_name") && d.has("node_path")){
					NodePath node_path = d["node_path"];
					Node *node = get_node_or_null(node_path);
					if(node && node->is_class("Node2D")){
						Node2D *node2d = (Node2D*) node;

						String slot_name = d["slot_name"];
						auto slot = skeleton->find_slot(slot_name);
						if(slot.is_valid()){
							auto bone = slot->get_bone();
							if(bone.is_valid())
							{
								update_bind_slot_node_transform(bone, node2d);
								update_bind_slot_node_draw_order(slot_name, node2d);
							}
						}

					}
				}
			}else if(a.get_type() == Variant::ARRAY){
				auto as = (Array) a;// 0: slot_name, 1: node_path
				if(as.size() >= 2 && as[0].get_type() == Variant::STRING && as[1].get_type() == Variant::NODE_PATH){
					NodePath node_path = as[1];
					Node *node = get_node_or_null(node_path);
					if(node && node->is_class("Node2D")){
						Node2D *node2d = (Node2D*) node;

						String slot_name = as[0];
						auto slot = skeleton->find_slot(slot_name);
						if(slot.is_valid()){
							auto bone = slot->get_bone();
							if(bone.is_valid())
							{
								update_bind_slot_node_transform(bone, node2d);
								update_bind_slot_node_draw_order(slot_name, node2d);
							}
						}

					}
				}
			}
		}
	}
}
void SpineSprite::update_bind_slot_node_transform(Ref<SpineBone> bone, Node2D *node2d){
	bone->apply_world_transform_2d(node2d);
}
void SpineSprite::update_bind_slot_node_draw_order(const String &slot_name, Node2D *node2d){
	auto mesh_ins = find_node(slot_name);
	if(mesh_ins){
		auto pos = mesh_ins->get_index();

		// get child
		auto node = find_child_node_by_node(node2d);
		if(node && node->get_index() != pos+1){
			move_child(node, pos+1);
		}
	}
}
Node *SpineSprite::find_child_node_by_node(Node *node){
	if(node == NULL) return NULL;
	while(node && node->get_parent() != this) node = node->get_parent();
	return node;
}

void SpineSprite::set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &s) {
    animation_state_data_res = s;

	// update run time skeleton and meshes
	_on_animation_data_changed();
}
Ref<SpineAnimationStateDataResource> SpineSprite::get_animation_state_data_res() {
    return animation_state_data_res;
}

void SpineSprite::_on_animation_data_created(){
//	print_line("_on_animation_data_created");
	skeleton = Ref<SpineSkeleton>(memnew(SpineSkeleton));
	skeleton->load_skeleton(animation_state_data_res->get_skeleton());
//	print_line("Run time skeleton created.");

	animation_state = Ref<SpineAnimationState>(memnew(SpineAnimationState));
	animation_state->load_animation_state(animation_state_data_res);
	animation_state->get_animation_state()->setListener(this);
//	print_line("Run time animation state created.");

	// add mesh instances related by current skeleton
	animation_state->update(0);
	animation_state->apply(skeleton);
	skeleton->update_world_transform();
	gen_mesh_from_skeleton(skeleton);

	_notification(NOTIFICATION_INTERNAL_PROCESS);

	emit_signal("animation_state_ready", animation_state, skeleton);
}
void SpineSprite::_on_animation_data_changed() {
//	print_line("_on_animation_data_changed");
	remove_mesh_instances();
	skeleton.unref();
	animation_state.unref();
	if(!animation_state_data_res.is_null())
	{
		if(!animation_state_data_res->is_connected("animation_state_data_created", this, "_on_animation_data_created"))
			animation_state_data_res->connect("animation_state_data_created", this, "_on_animation_data_created");
		if(!animation_state_data_res->is_connected("skeleton_data_res_changed", this, "_on_animation_data_changed"))
			animation_state_data_res->connect("skeleton_data_res_changed", this, "_on_animation_data_changed");
		if(!animation_state_data_res->is_connected("animation_state_data_changed", this, "_on_animation_data_changed"))
			animation_state_data_res->connect("animation_state_data_changed", this, "_on_animation_data_changed");

		if(animation_state_data_res->is_animation_state_data_created())
		{
			_on_animation_data_created();
		}
	}
}

Ref<SpineSkeleton> SpineSprite::get_skeleton() {
	return skeleton;
}
Ref<SpineAnimationState> SpineSprite::get_animation_state() {
	return animation_state;
}

void SpineSprite::gen_mesh_from_skeleton(Ref<SpineSkeleton> s) {
	auto sk = s->get_spine_object();
	for(size_t i=0, n = sk->getSlots().size(); i < n; ++i)
	{
		// creat a mesh instance 2d for every slot
		auto mesh_ins = memnew(SpineSpriteMeshInstance2D);
		add_child(mesh_ins);
		mesh_ins->set_position(Vector2(0, 0));
		mesh_ins->set_owner(this);
		mesh_instances.push_back(mesh_ins);

		spine::Slot *slot = sk->getDrawOrder()[i];
		mesh_ins->set_name(slot->getData().getName().buffer());
		Ref<SpineSlot> gd_slot(memnew(SpineSlot));
		gd_slot->set_spine_object(slot);
		mesh_ins->set_slot(gd_slot);

		// creat a material
		Ref<CanvasItemMaterial> mat(memnew(CanvasItemMaterial));
		CanvasItemMaterial::BlendMode blend_mode;
		switch (slot->getData().getBlendMode()) {
			case spine::BlendMode_Normal:
				blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
				break;
			case spine::BlendMode_Additive:
				blend_mode = CanvasItemMaterial::BLEND_MODE_ADD;
				break;
			case spine::BlendMode_Multiply:
				blend_mode = CanvasItemMaterial::BLEND_MODE_MUL;
				break;
			case spine::BlendMode_Screen:
				blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
				break;
			default:
				blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
		}		
		mat->set_blend_mode(blend_mode);		
		mesh_ins->set_material(mat);
	}
}

void SpineSprite::remove_mesh_instances() {
	for(size_t i=0;i < mesh_instances.size();++i)
	{
		remove_child(mesh_instances[i]);
		memdelete(mesh_instances[i]);
	}
	mesh_instances.clear();
}

void SpineSprite::remove_redundant_mesh_instances() {
	Vector<Node*> ms;
	// remove the redundant mesh instances that added by duplicating
//	print_line("start clearing");
	for(size_t i=0, n=get_child_count(); i<n; ++i){
		auto node = get_child(i);
//		print_line(String("get a node: ") + node->get_name());
		if(node && node->is_class("SpineSpriteMeshInstance2D")){
			if(mesh_instances.find((SpineSpriteMeshInstance2D*)node) == -1)
			{
//				print_line("marked clear");
				ms.push_back(node);
			}

		}
	}
	for(size_t i=0, n=ms.size(); i<n; ++i){
		remove_child(ms[i]);
		memdelete(ms[i]);
	}
	ms.clear();
//	print_line("end clearing");
}

#define TEMP_COPY(t, get_res) do{auto &temp_uvs = get_res;        \
								t.setSize(temp_uvs.size(), 0);    \
								for(size_t j=0;j<t.size();++j)    \
								{                                 \
								t[j] = temp_uvs[j];               \
								}}while(false);
void SpineSprite::update_mesh_from_skeleton(Ref<SpineSkeleton> s) {
	static const unsigned short VERTEX_STRIDE = 2;
	static const unsigned short UV_STRIDE = 2;
	static unsigned short quad_indices[] = { 0, 1, 2, 2, 3, 0 };

	auto sk = s->get_spine_object();
	for(size_t i=0, n = sk->getSlots().size(); i < n; ++i)
	{
		spine::Vector<float> vertices;
		spine::Vector<float> uvs;
		spine::Vector<unsigned short> indices;

		spine::Slot *slot = sk->getDrawOrder()[i];

		spine::Attachment *attachment = slot->getAttachment();
		if(!attachment){
			// set invisible to mesh instance
			mesh_instances[i]->set_visible(false);

			skeleton_clipper->clipEnd(*slot);
			continue;
		}
		mesh_instances[i]->set_visible(true);

		spine::Color skeleton_color = sk->getColor();
		spine::Color slot_color = slot->getColor();
		spine::Color tint(skeleton_color.r * slot_color.r, skeleton_color.g * slot_color.g, skeleton_color.b * slot_color.b, skeleton_color.a * slot_color.a);

		Ref<Texture> tex;
		Ref<Texture> normal_tex;
		size_t v_num = 0;

		if(attachment->getRTTI().isExactly(spine::RegionAttachment::rtti))
		{
			spine::RegionAttachment *region_attachment = (spine::RegionAttachment*)attachment;

			auto p_spine_renderer_object = (SpineRendererObject*) ((spine::AtlasRegion*)region_attachment->getRendererObject())->page->getRendererObject();
			tex = p_spine_renderer_object->tex;
			normal_tex = p_spine_renderer_object->normal_tex;

			v_num = 4;
			vertices.setSize(v_num * VERTEX_STRIDE, 0);

			region_attachment->computeWorldVertices(slot->getBone(), vertices, 0);

			TEMP_COPY(uvs, region_attachment->getUVs());

			indices.setSize(sizeof(quad_indices) / sizeof(unsigned short), 0);
			for (size_t j = 0, qn = indices.size();j<qn;++j) {
				indices[j] = quad_indices[j];
			}

			auto attachment_color = region_attachment->getColor();
			tint.r *= attachment_color.r;
			tint.g *= attachment_color.g;
			tint.b *= attachment_color.b;
			tint.a *= attachment_color.a;
		}else if(attachment->getRTTI().isExactly(spine::MeshAttachment::rtti)) {
			spine::MeshAttachment *mesh = (spine::MeshAttachment*) attachment;

			auto p_spine_renderer_object = (SpineRendererObject*) ((spine::AtlasRegion*)mesh->getRendererObject())->page->getRendererObject();
			tex = p_spine_renderer_object->tex;
			normal_tex = p_spine_renderer_object->normal_tex;

			v_num = mesh->getWorldVerticesLength()/VERTEX_STRIDE;
			vertices.setSize(mesh->getWorldVerticesLength(), 0);

			mesh->computeWorldVertices(*slot, vertices);

//			uvs = mesh->getUVs();
//			indices = mesh->getTriangles();
			TEMP_COPY(uvs, mesh->getUVs());
			TEMP_COPY(indices, mesh->getTriangles());

			auto attachment_color = mesh->getColor();
			tint.r *= attachment_color.r;
			tint.g *= attachment_color.g;
			tint.b *= attachment_color.b;
			tint.a *= attachment_color.a;
		} else if (attachment->getRTTI().isExactly(spine::ClippingAttachment::rtti)) {
			auto clip = (spine::ClippingAttachment *) attachment;
			skeleton_clipper->clipStart(*slot, clip);
			continue;
		} else {
			skeleton_clipper->clipEnd(*slot);
			continue;
		}

		auto mesh_ins = mesh_instances[i];
		VisualServer::get_singleton()->canvas_item_clear(mesh_ins->get_canvas_item());	

		if (skeleton_clipper->isClipping()) {
			skeleton_clipper->clipTriangles(vertices, indices, uvs, VERTEX_STRIDE);

			if (skeleton_clipper->getClippedTriangles().size() == 0) {
				skeleton_clipper->clipEnd(*slot);
				continue;
			}

			auto &clipped_vertices = skeleton_clipper->getClippedVertices();
			v_num = clipped_vertices.size()/VERTEX_STRIDE;
			auto &clipped_uvs = skeleton_clipper->getClippedUVs();
			auto &clipped_indices = skeleton_clipper->getClippedTriangles();

			if (indices.size() > 0) {
				Vector<Vector2> p_points, p_uvs;
				Vector<Color> p_colors;
				Vector<int> p_indices;
				p_points.resize(v_num);
				p_uvs.resize(v_num);
				p_colors.resize(v_num);
				for (size_t j = 0; j < v_num; j++) {
					p_points.set(j, Vector2(clipped_vertices[j*VERTEX_STRIDE], -clipped_vertices[j*VERTEX_STRIDE+1]));
					p_uvs.set(j, Vector2(clipped_uvs[j*VERTEX_STRIDE], clipped_uvs[j*VERTEX_STRIDE+1]));
					p_colors.set(j, Color(tint.r, tint.g, tint.b, tint.a));
				}
				p_indices.resize(clipped_indices.size());
				for (size_t j = 0; j < clipped_indices.size(); ++j) {
					p_indices.set(j, clipped_indices[j]);
				}

				VisualServer::get_singleton()->canvas_item_add_triangle_array(mesh_ins->get_canvas_item(),
																			  p_indices,
																			  p_points,
																			  p_colors,
																			  p_uvs,
																			  Vector<int>(),
																			  Vector<float>(),
																			  tex.is_null() ? RID() : tex->get_rid(),
																			  -1,
																			  normal_tex.is_null() ? RID() : normal_tex->get_rid());
			}
		}else {
			if (indices.size() > 0) {
				Vector<Vector2> p_points, p_uvs;
				Vector<Color> p_colors;
				Vector<int> p_indices;
				p_points.resize(v_num);
				p_uvs.resize(v_num);
				p_colors.resize(v_num);
				for (size_t j = 0; j < v_num; j++) {
					p_points.set(j, Vector2(vertices[j*VERTEX_STRIDE], -vertices[j*VERTEX_STRIDE+1]));
					p_uvs.set(j, Vector2(uvs[j*VERTEX_STRIDE], uvs[j*VERTEX_STRIDE+1]));
					p_colors.set(j, Color(tint.r, tint.g, tint.b, tint.a));
				}
				p_indices.resize(indices.size());
				for (size_t j = 0; j < indices.size(); ++j) {
					p_indices.set(j, indices[j]);
				}

				VisualServer::get_singleton()->canvas_item_add_triangle_array(mesh_ins->get_canvas_item(),
																			  p_indices,
																			  p_points,
																			  p_colors,
																			  p_uvs,
																			  Vector<int>(),
																			  Vector<float>(),
																			  tex.is_null() ? RID() : tex->get_rid(),
																			  -1,
																			  normal_tex.is_null() ? RID() : normal_tex->get_rid());
			}
		}
		skeleton_clipper->clipEnd(*slot);

		if (mesh_ins->get_material()->is_class("CanvasItemMaterial")){
			Ref<CanvasItemMaterial> mat = mesh_ins->get_material();
			CanvasItemMaterial::BlendMode blend_mode;
			switch (slot->getData().getBlendMode()) {
				case spine::BlendMode_Normal:
					blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
					break;
				case spine::BlendMode_Additive:
					blend_mode = CanvasItemMaterial::BLEND_MODE_ADD;
					break;
				case spine::BlendMode_Multiply:
					blend_mode = CanvasItemMaterial::BLEND_MODE_MUL;
					break;
				case spine::BlendMode_Screen:
					blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
					break;
				default:
					blend_mode = CanvasItemMaterial::BLEND_MODE_MIX;
			}		
			mat->set_blend_mode(blend_mode);
		}
	}
	skeleton_clipper->clipEnd();
}
#undef TEMP_COPY

void SpineSprite::callback(spine::AnimationState *state, spine::EventType type, spine::TrackEntry *entry, spine::Event *event) {
	Ref<SpineTrackEntry> gd_entry(NULL);
	Ref<SpineEvent> gd_event(NULL);

	if(entry){
		gd_entry = Ref<SpineTrackEntry>(memnew(SpineTrackEntry));
		gd_entry->set_spine_object(entry);
	}
	if(event){
		gd_event = Ref<SpineEvent>(memnew(SpineEvent));
		gd_event->set_spine_object(event);
	}

	switch (type) {
		case spine::EventType_Start:
		{
			emit_signal("animation_start", animation_state, gd_entry, gd_event);
		}break;
		case spine::EventType_Interrupt:
		{
			emit_signal("animation_interrupt", animation_state, gd_entry, gd_event);
		}break;
		case spine::EventType_End:
		{
			emit_signal("animation_end", animation_state, gd_entry, gd_event);
		}break;
		case spine::EventType_Complete:
		{
			emit_signal("animation_complete", animation_state, gd_entry, gd_event);
		}break;
		case spine::EventType_Dispose:
		{
			emit_signal("animation_dispose", animation_state, gd_entry, gd_event);
		}break;
		case spine::EventType_Event:
		{
			emit_signal("animation_event", animation_state, gd_entry, gd_event);
		}break;
	}
}

// External feature functions
Array SpineSprite::get_current_animations() {
	return current_animations;
}
void SpineSprite::set_current_animations(Array as) {
	current_animations = as;

	// validate it then play the animations
	if(animation_state.is_valid() && skeleton.is_valid()){
		for(size_t i=0; i<current_animations.size(); ++i){
			auto a = current_animations[i];
			if(a.get_type() == Variant::DICTIONARY){
				Dictionary d = a;
				if(d.has("animation_name") && d.has("track_id")){
					String animation_name = d["animation_name"];
					int track_id = d["track_id"];
					if(track_id < 0){
						print_line(String("track_id at ") + String(Variant((int)i)) + String(" can not less than 0!"));
						continue;
					}
					if(skeleton->get_data()->find_animation(animation_name).is_valid()){
						bool loop = d.has("loop") ? ((bool)d["loop"]) : true;
						animation_state->set_animation(animation_name, loop, track_id);
					} else{
//						print_line(String("Can't not find animation '") + animation_name + String("'"));
						continue;
					}
				}
			}else if(a.get_type() == Variant::ARRAY){
				Array as = a;
				if(as.size() >= 1 && as[0].get_type() == Variant::STRING){
					String anim_name = as[0];
					bool loop = as.size() >= 2 && as[1].get_type() == Variant::BOOL ? (bool)as[1] : true;
					int track_id = as.size() >= 3 && as[2].get_type() == Variant::INT ? (int)as[2] : (int)i;
					if(track_id < 0){
						print_line(String("track_id at ") + String(Variant((int)i)) + String(" can not less than 0!"));
						continue;
					}
					auto anim = skeleton->get_data()->find_animation(anim_name);
					if(anim.is_valid()){
						animation_state->set_animation_by_ref(anim, loop, track_id);
					} else{
//						print_line(String("Can't not find animation '") + anim_name + String("'"));
						continue;
					}
				}
			}else if(a.get_type() == Variant::STRING){
				auto anim = skeleton->get_data()->find_animation(a);
				if(anim.is_valid()){
					animation_state->set_animation_by_ref(anim, true, i);
				} else{
					continue;
				}
			}
		}
	}
}

int SpineSprite::get_select_track_id(){
	return select_track_id;
}
void SpineSprite::set_select_track_id(int v){
	select_track_id = v;

	if(select_track_id < 0) select_track_id = 0;
}

bool SpineSprite::get_clear_track(){
	return false;
}
void SpineSprite::set_clear_track(bool v){
	if(v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->clear_track(select_track_id);
}

bool SpineSprite::get_clear_tracks(){
	return false;
}
void SpineSprite::set_clear_tracks(bool v){
	if(v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->clear_tracks();
}

float SpineSprite::get_empty_animation_duration(){
	return empty_animation_duration;
}
void SpineSprite::set_empty_animation_duration(float v){
	empty_animation_duration = v;
}

bool SpineSprite::get_set_empty_animation(){
	return false;
}
void SpineSprite::set_set_empty_animation(bool v){
	if(v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->set_empty_animation(select_track_id, empty_animation_duration);
}

bool SpineSprite::get_set_empty_animations(){
	return false;
}
void SpineSprite::set_set_empty_animations(bool v){
	if(v && animation_state.is_valid() && skeleton.is_valid())
		animation_state->set_empty_animations(empty_animation_duration);
}

Array SpineSprite::get_bind_slot_nodes(){
	return bind_slot_nodes;
}
void SpineSprite::set_bind_slot_nodes(Array v) {
	bind_slot_nodes = v;
}

bool SpineSprite::get_overlap(){
	return overlap;
}
void SpineSprite::set_overlap(bool v){
	overlap = v;
}

void SpineSprite::set_skin(Ref<PackedSpineSkinResource> v)
{
	if(v != skin && skin.is_valid()){
		if(skin->is_connected("property_changed", this, "_on_skin_property_changed"))
			skin->disconnect("property_changed", this, "_on_skin_property_changed");
	}

	skin = v;

	if(skin.is_valid()){
		if(!skin->is_connected("property_changed", this, "_on_skin_property_changed"))
			skin->connect("property_changed", this, "_on_skin_property_changed");
		update_runtime_skin();
	}
}
Ref<PackedSpineSkinResource> SpineSprite::get_skin(){
	return skin;
}
void SpineSprite::update_runtime_skin(){
	auto new_skin = gen_spine_skin_from_packed_resource(skin);

	if(new_skin.is_valid())
	{
		skeleton->set_skin(new_skin);
		skeleton->set_to_setup_pose();
	}
}
void SpineSprite::_on_skin_property_changed(){
	update_runtime_skin();
}

Ref<SpineSkin> SpineSprite::gen_spine_skin_from_packed_resource(Ref<PackedSpineSkinResource> res){
	if(!(animation_state.is_valid() && skeleton.is_valid()))
		return NULL;
	if(!res.is_valid())
		return NULL;
	if(res->get_skin_name().empty())
		return NULL;
	auto exist_skin = animation_state_data_res->get_skeleton()->find_skin(res->get_skin_name());
	if(exist_skin.is_valid())
	{
		return exist_skin;
	}

	auto new_skin = Ref<SpineSkin>(memnew(SpineSkin))->init(res->get_skin_name());
	auto sub_skin_names = res->get_sub_skin_names();
	for(size_t i=0;i<sub_skin_names.size();++i)
	{
		auto skin_name = (String)sub_skin_names[i];
		auto sub_skin = animation_state_data_res->get_skeleton()->find_skin(skin_name);
		if(sub_skin.is_valid())
			new_skin->add_skin(sub_skin);
	}
	return new_skin;
}

void SpineSprite::bind_slot_with_node_2d(const String &slot_name, Node2D *n){
	auto node_path = n->get_path_to(this);

	// check if has the same binding
	for(size_t i=0, size=bind_slot_nodes.size(); i<size; ++i){
		auto a = bind_slot_nodes[i];
		if(a.get_type() == Variant::DICTIONARY){
			auto d = (Dictionary) a;
			if(d.has("slot_name") && d.has("node_path")){
				if(slot_name == d["slot_name"] && node_path == d["node_path"]){
					return;
				}
			}
		}else if(a.get_type() == Variant::ARRAY){
			auto as = (Array) a;
			if(as.size() >= 2 && as[0].get_type() == Variant::STRING && as[1].get_type() == Variant::NODE_PATH){
				if(slot_name == as[0] && node_path == as[1]){
					return;
				}
			}
		}
	}

	Array bound;
	bound.resize(2);
	bound[0] = slot_name;
	bound[1] = node_path;

	bind_slot_nodes.append(bound);
}
void SpineSprite::unbind_slot_with_node_2d(const String &slot_name, Node2D *n){
	auto node_path = n->get_path_to(this);

	for(size_t i=0, size=bind_slot_nodes.size(); i<size; ++i){
		auto a = bind_slot_nodes[i];
		if(a.get_type() == Variant::DICTIONARY){
			auto d = (Dictionary) a;
			if(d.has("slot_name") && d.has("node_path")){
				if(slot_name == d["slot_name"] && node_path == d["node_path"]){
					bind_slot_nodes.remove(i);
					return;
				}
			}
		}else if(a.get_type() == Variant::ARRAY){
			auto as = (Array) a;
			if(as.size() >= 2 && as[0].get_type() == Variant::STRING && as[1].get_type() == Variant::NODE_PATH){
				if(slot_name == as[0] && node_path == as[1]){
					bind_slot_nodes.remove(i);
					return;
				}
			}
		}
	}
}

