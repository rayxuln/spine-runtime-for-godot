//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineSkinAttachmentMapEntries.h"

void SpineSkinAttachmentMapEntry::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_slot_index"), &SpineSkinAttachmentMapEntry::get_slot_index);
	ClassDB::bind_method(D_METHOD("set_slot_index", "v"), &SpineSkinAttachmentMapEntry::set_slot_index);
	ClassDB::bind_method(D_METHOD("get_entry_name"), &SpineSkinAttachmentMapEntry::get_entry_name);
	ClassDB::bind_method(D_METHOD("set_entry_name", "v"), &SpineSkinAttachmentMapEntry::set_entry_name);
	ClassDB::bind_method(D_METHOD("get_attachment"), &SpineSkinAttachmentMapEntry::get_attachment);
	ClassDB::bind_method(D_METHOD("set_attachment", "v"), &SpineSkinAttachmentMapEntry::set_attachment);
}

SpineSkinAttachmentMapEntry::SpineSkinAttachmentMapEntry():entry(NULL) {}
SpineSkinAttachmentMapEntry::~SpineSkinAttachmentMapEntry() {}

uint64_t SpineSkinAttachmentMapEntry::get_slot_index(){
	return entry->_slotIndex;
}
void SpineSkinAttachmentMapEntry::set_slot_index(uint64_t v){
	entry->_slotIndex = v;
}

String SpineSkinAttachmentMapEntry::get_entry_name(){
	return entry->_name.buffer();
}
void SpineSkinAttachmentMapEntry::set_entry_name(const String &v){
	entry->_name = spine::String(v.utf8());
}

Ref<SpineAttachment> SpineSkinAttachmentMapEntry::get_attachment(){
	if(entry->_attachment == NULL) return NULL;
	Ref<SpineAttachment> gd_attachment(memnew(SpineAttachment));
	gd_attachment->set_spine_object(entry->_attachment);
	return gd_attachment;
}
void SpineSkinAttachmentMapEntry::set_attachment(Ref<SpineAttachment> v){
	if(v.is_valid()){
		entry->_attachment = v->get_spine_object();
	}else{
		entry->_attachment = NULL;
	}
}

void SpineSkinAttachmentMapEntries::_bind_methods() {
	ClassDB::bind_method(D_METHOD("has_next"), &SpineSkinAttachmentMapEntries::has_next);
	ClassDB::bind_method(D_METHOD("next"), &SpineSkinAttachmentMapEntries::next);
}

SpineSkinAttachmentMapEntries::SpineSkinAttachmentMapEntries():entries(NULL) {}
SpineSkinAttachmentMapEntries::~SpineSkinAttachmentMapEntries() {
	if(entries){
		delete entries;
		return;
	}
}

bool SpineSkinAttachmentMapEntries::has_next(){
	return entries->hasNext();
}
Ref<SpineSkinAttachmentMapEntry> SpineSkinAttachmentMapEntries::next(){
	auto &e = entries->next();
	Ref<SpineSkinAttachmentMapEntry> gd_entry(memnew(SpineSkinAttachmentMapEntry));
	gd_entry->set_spine_object(&e);
	return gd_entry;
}