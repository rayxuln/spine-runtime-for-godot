//
// Created by Raiix on 2020/7/12.
//

#ifndef GODOT_PACKEDSPINESKINRESOURCE_H
#define GODOT_PACKEDSPINESKINRESOURCE_H

#include "core/variant_parser.h"

#include "SpineSkin.h"

class PackedSpineSkinResource : public Resource{
	GDCLASS(PackedSpineSkinResource, Resource);

protected:
	static void _bind_methods();

private:
	String skin_name;
	Array sub_skin_names;

public:
	PackedSpineSkinResource();
	virtual ~PackedSpineSkinResource();

	void set_skin_name(const String &v);
	String get_skin_name();

	void set_sub_skin_names(Array v);
	Array get_sub_skin_names();

};

#endif //GODOT_PACKEDSPINESKINRESOURCE_H
