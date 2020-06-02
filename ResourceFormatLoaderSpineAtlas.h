//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
#define GODOT_RESOURCEFORMATLOADERSPINEATLAS_H

#include "core/io/resource_loader.h"

class ResourceFormatLoaderSpineAtlas : public ResourceFormatLoader{
    GDCLASS(ResourceFormatLoaderSpineAtlas, ResourceFormatLoader);
public:
    virtual RES load(const String &p_path, const String &p_original_path, Error *r_error = NULL);
    virtual void get_recognized_extensions(List<String> *r_extensions) const;
    virtual bool handles_type(const String &p_type) const;
    virtual String get_resource_type(const String &p_path) const;
};


#endif //GODOT_RESOURCEFORMATLOADERSPINEATLAS_H
