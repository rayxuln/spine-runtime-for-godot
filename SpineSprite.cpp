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

	ADD_SIGNAL(MethodInfo("animation_state_ready", PropertyInfo(Variant::OBJECT, "animation_state"), PropertyInfo(Variant::OBJECT, "skeleton")));

    ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "animation_state_data_res", PropertyHint::PROPERTY_HINT_RESOURCE_TYPE, "SpineAnimationStateDataResource"), "set_animation_state_data_res", "get_animation_state_data_res");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "skeleton"), "", "get_skeleton");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "animation_state"), "", "get_animation_state");
}

void SpineSprite::_notification(int p_what) {
	switch (p_what) {

		case NOTIFICATION_DRAW: {

			if (skeleton.is_null() || animation_state.is_null())
				return;

			animation_state->update(get_process_delta_time());
			animation_state->apply(skeleton);

			skeleton->update_world_transform();

			draw_skeleton(skeleton);

//			RID ci = get_canvas_item();
		} break;
	}
}

void SpineSprite::set_animation_state_data_res(const Ref<SpineAnimationStateDataResource> &s) {
    animation_state_data_res = s;

	if(!animation_state_data_res.is_null())
	{
		skeleton.unref();
		animation_state.unref();

		animation_state_data_res->connect("animation_state_data_created", this, "_on_animation_data_created");

		if(animation_state_data_res->is_animation_state_data_created())
		{
			_on_animation_data_created();
		}
	}
}
Ref<SpineAnimationStateDataResource> SpineSprite::get_animation_state_data_res() {
    return animation_state_data_res;
}

void SpineSprite::_on_animation_data_created(){
	skeleton = Ref<SpineSkeleton>(memnew(SpineSkeleton));
	skeleton->load_skeleton(animation_state_data_res->get_skeleton());
	print_line("Run time skeleton created.");

	animation_state = Ref<SpineAnimationState>(memnew(SpineAnimationState));
	animation_state->load_animation_state(animation_state_data_res);
	print_line("Run time animation state created.");

	update();

	emit_signal("animation_state_ready", animation_state, skeleton);
}

Ref<SpineSkeleton> SpineSprite::get_skeleton() {
	return skeleton;
}
Ref<SpineAnimationState> SpineSprite::get_animation_state() {
	return animation_state;
}

void SpineSprite::draw_skeleton(Ref<SpineSkeleton> s) {
	static unsigned short quad_indices[] = {0, 1, 2, 2, 3, 0};

	auto sk = s->get_skeleton();
	for(size_t i=0, n = sk->getSlots().size(); i < n; ++i)
	{
		spine::Slot *slot = sk->getDrawOrder()[i];

		spine::Attachment *attachment = slot->getAttachment();
		if(!attachment) continue;

		int blend_mode;
		switch (slot->getData().getBlendMode()) {
			case spine::BlendMode_Normal:
				blend_mode = 0;
				break;
			case spine::BlendMode_Additive:
				blend_mode = 1;
				break;
			case spine::BlendMode_Multiply:
				blend_mode = 2;
				break;
			case spine::BlendMode_Screen:
				blend_mode = 3;
				break;
			default:
				blend_mode = 0;
		}

		spine::Color skeleton_color = sk->getColor();
		spine::Color slot_color = slot->getColor();
		spine::Color tint(skeleton_color.r * slot_color.r, skeleton_color.g * slot_color.g, skeleton_color.b * slot_color.b, skeleton_color.a * slot_color.a);

		Ref<Texture> tex;
		if(attachment->getRTTI().isExactly(spine::RegionAttachment::rtti))
		{
			spine::RegionAttachment *region_attachment = (spine::RegionAttachment*)attachment;

			tex = *((Ref<ImageTexture>*)((spine::AtlasRegion*)region_attachment->getRendererObject())->page->getRendererObject());


		}

		print_line("drawing spine skeleton...");
	}
}