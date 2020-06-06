//
// Created by Raymond_Lx on 2020/6/5.
//

#include "SpineAttachment.h"

void SpineAttachment::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_attachment_name"), &SpineAttachment::get_attachment_name);
	ClassDB::bind_method(D_METHOD("copy"), &SpineAttachment::copy);
}

SpineAttachment::SpineAttachment():attachment(NULL) {}
SpineAttachment::~SpineAttachment() {
	if(attachment){
		attachment->dereference();
		attachment = NULL;
	}
}

String SpineAttachment::get_attachment_name(){
	return attachment->getName().buffer();
}

Ref<SpineAttachment> SpineAttachment::copy(){
	auto a = attachment->copy();
	if(a == NULL) return NULL;
	Ref<SpineAttachment> gd_attachment(memnew(SpineAttachment));
	gd_attachment->set_spine_object(a);
	return gd_attachment;
}