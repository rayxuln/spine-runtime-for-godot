//
// Created by Raymond_Lx on 2020/6/5.
//

#ifndef GODOT_SPINESKINATTACHMENTMAPENTRIES_H
#define GODOT_SPINESKINATTACHMENTMAPENTRIES_H

#include "core/variant_parser.h"

#include <spine/spine.h>

#include "SpineAttachment.h"

class SpineSkinAttachmentMapEntry : public Reference {
	GDCLASS(SpineSkinAttachmentMapEntry, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skin::AttachmentMap::Entry *entry;

public:
	SpineSkinAttachmentMapEntry();
	~SpineSkinAttachmentMapEntry();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entry *e){
		entry = e;
	}
	inline spine::Skin::AttachmentMap::Entry *get_spine_object(){
		return entry;
	}

	uint64_t get_slot_index();
	void set_slot_index(uint64_t v);

	String get_entry_name();
	void set_entry_name(const String &v);

	Ref<SpineAttachment> get_attachment();
	void set_attachment(Ref<SpineAttachment> v);
};

class SpineSkinAttachmentMapEntries : public Reference {
	GDCLASS(SpineSkinAttachmentMapEntries, Reference);

protected:
	static void _bind_methods();

private:
	spine::Skin::AttachmentMap::Entries *entries;

public:
	SpineSkinAttachmentMapEntries();
	~SpineSkinAttachmentMapEntries();

	inline void set_spine_object(spine::Skin::AttachmentMap::Entries *e){
		entries = e;
	}
	inline spine::Skin::AttachmentMap::Entries *get_spine_object(){
		return entries;
	}

	bool has_next();
	Ref<SpineSkinAttachmentMapEntry> next();
};

#endif //GODOT_SPINESKINATTACHMENTMAPENTRIES_H
