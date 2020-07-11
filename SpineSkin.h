//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINESKIN_H
#define GODOT_SPINESKIN_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineAttachment.h"
#include "SpineSkinAttachmentMapEntries.h"

class SpineSkin : public Reference {
	GDCLASS(SpineSkin, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skin *skin;

public:
	SpineSkin();
	~SpineSkin();

	inline void set_spine_object(spine::Skin *s){
		skin = s;
	}
	spine::Skin *get_spine_object(){
		return skin;
	}

	Ref<SpineSkin> init(const String &name);

	void set_attachment(uint64_t slot_index, const String &name, Ref<SpineAttachment> attachment);

	Ref<SpineAttachment> get_attachment(uint64_t slot_index, const String &name);

	void remove_attachment(uint64_t slot_index, const String &name);

	Array find_names_for_slot(uint64_t slot_index);

	Array find_attachments_for_slot(uint64_t slot_index);

	String get_skin_name();

	void add_skin(Ref<SpineSkin> other);

	void copy_skin(Ref<SpineSkin> other);

	Ref<SpineSkinAttachmentMapEntries> get_attachments();

	Array get_bones();

	Array get_constraint();
};

#endif //GODOT_SPINESKIN_H
