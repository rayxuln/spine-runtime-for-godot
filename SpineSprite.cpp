//
// Created by Raymond_Lx on 2020/6/2.
//

#include "SpineSprite.h"



void SpineSprite::_bind_methods() {
    ClassDB::bind_method(D_METHOD("set_animation_state_data_res", "animation_state_data_res"), &SpineSprite::set_animation_state_data_res);
    ClassDB::bind_method(D_METHOD("get_animation_state_data_res"), &SpineSprite::get_animation_state_data_res);
	ClassDB::bind_method(D_METHOD("_on_animation_data_created"), &SpineSprite::_on_animation_data_created);
	ClassDB::bind_method(D_METHOD("get_skeleton"), &SpineSprite::get_skeleton);
	ClassDB::bind_method(D_METHOD("get_animation_state"), &SpineSprite::get_animation_state);
	ClassDB::bind_method(D_METHOD("_on_animation_data_changed"), &SpineSprite::_on_animation_data_changed);

	ADD_SIGNAL(MethodInfo("animation_state_ready", PropertyInfo(Variant::OBJECT, "animation_state"), PropertyInfo(Variant::OBJECT, "skeleton")));

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "animation_state_data_res", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAnimationStateDataResource"), "set_animation_state_data_res", "get_animation_state_data_res");
}

void SpineSprite::_notification(int p_what) {
	switch (p_what) {
		case NOTIFICATION_READY:{
			set_process_internal(true);
		} break;
		case NOTIFICATION_INTERNAL_PROCESS: {
			if (!(skeleton.is_valid() && animation_state.is_valid()) || mesh_instances.size() == 0)
				return;

			animation_state->update(get_process_delta_time());
			animation_state->apply(skeleton);

			skeleton->update_world_transform();

			update_mesh_from_skeleton(skeleton);

			update();
		} break;
	}
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
	struct Vertex{
		float x, y;
		float u, v;

		spine::Color color;
	};
	static spine::Vector<Vertex> vertices;
	static unsigned short quad_indices[] = {0, 1, 2, 2, 3, 0};

	auto sk = s->get_skeleton();
	for(size_t i=0, n = sk->getSlots().size(); i < n; ++i)
	{
		spine::Slot *slot = sk->getDrawOrder()[i];

		spine::Attachment *attachment = slot->getAttachment();
		if(!attachment) continue;

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

		spine::Color skeleton_color = sk->getColor();
		spine::Color slot_color = slot->getColor();
		spine::Color tint(skeleton_color.r * slot_color.r, skeleton_color.g * slot_color.g, skeleton_color.b * slot_color.b, skeleton_color.a * slot_color.a);

		Ref<Texture> tex;
		PoolIntArray indices;
		size_t v_num = 0;
		if(attachment->getRTTI().isExactly(spine::RegionAttachment::rtti))
		{
			spine::RegionAttachment *region_attachment = (spine::RegionAttachment*)attachment;

			tex = *((Ref<ImageTexture>*)((spine::AtlasRegion*)region_attachment->getRendererObject())->page->getRendererObject());

			v_num = 4;
			vertices.setSize(v_num, Vertex());


			region_attachment->computeWorldVertices(slot->getBone(), &(vertices.buffer()->x), 0, sizeof(Vertex) / sizeof(float));

			for (size_t j=0, l=0; j < 4; ++j, l+=2)
			{
				Vertex &vertex = vertices[j];
				vertex.color.set(tint);
				vertex.u = region_attachment->getUVs()[l];
				vertex.v = region_attachment->getUVs()[l+1];
			}

			for(auto x : quad_indices)
			{
				indices.push_back(x);
			}
		}else if(attachment->getRTTI().isExactly(spine::MeshAttachment::rtti)) {
			spine::MeshAttachment *mesh = (spine::MeshAttachment*) attachment;

			tex = *(Ref<ImageTexture>*)((spine::AtlasRegion*)mesh->getRendererObject())->page->getRendererObject();

			v_num = mesh->getWorldVerticesLength()/2;
			vertices.setSize(v_num, Vertex());

			mesh->computeWorldVertices(*slot, 0, mesh->getWorldVerticesLength(), &(vertices.buffer()->x), 0, sizeof(Vertex) / sizeof(float));

			for(size_t j=0, l=0; j < v_num; ++j, l+=2)
			{
				Vertex &vertex = vertices[j];
				vertex.color.set(tint);
				vertex.u = mesh->getUVs()[l];
				vertex.v = mesh->getUVs()[l+1];
			}

			auto &ids = mesh->getTriangles();
			for(size_t j=0; j<ids.size(); ++j)
			{
				indices.push_back(ids[j]);
			}
		}

		// copy vertices, uvs, colors
		PoolVector2Array v2_array, uv_array;
		PoolColorArray color_array;
		for(size_t j=0; j < v_num; ++j)
		{
			v2_array.push_back(Vector2(vertices[j].x, -vertices[j].y));
			uv_array.push_back(Vector2(vertices[j].u, vertices[j].v));
			color_array.push_back(Color(vertices[j].color.r, vertices[j].color.g, vertices[j].color.b, vertices[j].color.a));
		}

		// create array mesh
		Ref<ArrayMesh> array_mesh = Ref<ArrayMesh>(memnew(ArrayMesh));
		Array as;
		as.resize(ArrayMesh::ARRAY_MAX);
		as[ArrayMesh::ARRAY_VERTEX] = v2_array;
		as[ArrayMesh::ARRAY_TEX_UV] = uv_array;
		as[ArrayMesh::ARRAY_COLOR] = color_array;
		as[ArrayMesh::ARRAY_INDEX] = indices;

		array_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, as);

		// create mesh instances
		auto mesh_ins = memnew(MeshInstance2D);
		add_child(mesh_ins);
		mesh_ins->set_position(Vector2(0, 0));
		mesh_ins->set_mesh(array_mesh);
		mesh_ins->set_texture(tex);
		Ref<CanvasItemMaterial> mat(memnew(CanvasItemMaterial));
		mesh_ins->set_material(mat);
		mat->set_blend_mode(blend_mode);
		mesh_instances.push_back(mesh_ins);
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

void SpineSprite::update_mesh_from_skeleton(Ref<SpineSkeleton> s) {
	struct Vertex{
		float x, y;
		float u, v;

		spine::Color color;
	};
	static spine::Vector<Vertex> vertices;
	static unsigned short quad_indices[] = {0, 1, 2, 2, 3, 0};

	auto sk = s->get_skeleton();
	size_t mi_index = 0;
	for(size_t i=0, n = sk->getSlots().size(); i < n; ++i)
	{
		spine::Slot *slot = sk->getDrawOrder()[i];

		spine::Attachment *attachment = slot->getAttachment();
		if(!attachment) continue;

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

		spine::Color skeleton_color = sk->getColor();
		spine::Color slot_color = slot->getColor();
		spine::Color tint(skeleton_color.r * slot_color.r, skeleton_color.g * slot_color.g, skeleton_color.b * slot_color.b, skeleton_color.a * slot_color.a);

		Ref<Texture> tex;
		PoolIntArray indices;
		size_t v_num = 0;
		if(attachment->getRTTI().isExactly(spine::RegionAttachment::rtti))
		{
			spine::RegionAttachment *region_attachment = (spine::RegionAttachment*)attachment;

			tex = *((Ref<ImageTexture>*)((spine::AtlasRegion*)region_attachment->getRendererObject())->page->getRendererObject());

			v_num = 4;
			vertices.setSize(v_num, Vertex());


			region_attachment->computeWorldVertices(slot->getBone(), &(vertices.buffer()->x), 0, sizeof(Vertex) / sizeof(float));

			for (size_t j=0, l=0; j < 4; ++j, l+=2)
			{
				Vertex &vertex = vertices[j];
				vertex.color.set(tint);
				vertex.u = region_attachment->getUVs()[l];
				vertex.v = region_attachment->getUVs()[l+1];
			}

			for(auto x : quad_indices)
			{
				indices.push_back(x);
			}
		}else if(attachment->getRTTI().isExactly(spine::MeshAttachment::rtti)) {
			spine::MeshAttachment *mesh = (spine::MeshAttachment*) attachment;

			tex = *(Ref<ImageTexture>*)((spine::AtlasRegion*)mesh->getRendererObject())->page->getRendererObject();

			v_num = mesh->getWorldVerticesLength()/2;
			vertices.setSize(v_num, Vertex());

			mesh->computeWorldVertices(*slot, 0, mesh->getWorldVerticesLength(), &(vertices.buffer()->x), 0, sizeof(Vertex) / sizeof(float));

			for(size_t j=0, l=0; j < v_num; ++j, l+=2)
			{
				Vertex &vertex = vertices[j];
				vertex.color.set(tint);
				vertex.u = mesh->getUVs()[l];
				vertex.v = mesh->getUVs()[l+1];
			}

			auto &ids = mesh->getTriangles();
			for(size_t j=0; j<ids.size(); ++j)
			{
				indices.push_back(ids[j]);
			}
		}

		// copy vertices, uvs, colors
		PoolVector2Array v2_array, uv_array;
		PoolColorArray color_array;
		for(size_t j=0; j < v_num; ++j)
		{
			v2_array.push_back(Vector2(vertices[j].x, -vertices[j].y));
			uv_array.push_back(Vector2(vertices[j].u, vertices[j].v));
			color_array.push_back(Color(vertices[j].color.r, vertices[j].color.g, vertices[j].color.b, vertices[j].color.a));
		}

		// create array mesh
		Ref<ArrayMesh> array_mesh = Ref<ArrayMesh>(memnew(ArrayMesh));
		Array as;
		as.resize(ArrayMesh::ARRAY_MAX);
		as[ArrayMesh::ARRAY_VERTEX] = v2_array;
		as[ArrayMesh::ARRAY_TEX_UV] = uv_array;
		as[ArrayMesh::ARRAY_COLOR] = color_array;
		as[ArrayMesh::ARRAY_INDEX] = indices;

		array_mesh->add_surface_from_arrays(Mesh::PRIMITIVE_TRIANGLES, as);

		// store the mesh and tex
		Dictionary dic;
		dic["mesh"] = array_mesh;
		dic["tex"] = tex;

		// update mesh instances
		if(mi_index < mesh_instances.size())
		{
			auto mesh_ins = mesh_instances[mi_index];
			mesh_ins->set_mesh(array_mesh);
			mesh_ins->set_texture(tex);
			Ref<CanvasItemMaterial> mat = mesh_ins->get_material();
			mat->set_blend_mode(blend_mode);
		}


		mi_index += 1;
	}
}