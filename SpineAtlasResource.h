//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINEATLASRESOURCE_H
#define GODOT_SPINEATLASRESOURCE_H



#include "core/variant_parser.h"

#include <spine/SpineString.h>
#include <spine/TextureLoader.h>
#include <spine/Atlas.h>
#include <scene/resources/texture.h>
#include <core/io/image_loader.h>
#include "SpineRendererObject.h"

class SpineAtlasResource : public Resource{
    GDCLASS(SpineAtlasResource, Resource);
protected:
    static void _bind_methods();

private:
    spine::Atlas *atlas;

public:
	Array texes;
    Array normal_texes;

    Error load_file(const String &p_path);

	void set_textures(const Array &ts);
	Array get_textures();

	void set_normal_textures(const Array &ts);
	Array get_normal_textures();    

	inline spine::Atlas *get_spine_atlas(){return atlas;}

	SpineAtlasResource();
    virtual ~SpineAtlasResource();
};


#endif //GODOT_SPINEATLASRESOURCE_H
