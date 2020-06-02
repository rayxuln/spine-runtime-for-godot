//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineAtlasResource.h"

RES ResourceFormatLoaderSpineAtlas::load(const String &p_path, const String &p_original_path, Error *r_error) {
    Ref<SpineAtlasResource> atlas = memnew(SpineAtlasResource);
    Error err = atlas->load_file(p_path);
    if(r_error){
        *r_error = err;
    }
    return atlas;
}

void ResourceFormatLoaderSpineAtlas::get_recognized_extensions(List<String> *r_extensions) const {
    const char atlas_ext[] = "atlas";
    if(!r_extensions->find(atlas_ext)) {
        r_extensions->push_back(atlas_ext);
    }
}

String ResourceFormatLoaderSpineAtlas::get_resource_type(const String &p_path) const {
    return "Resource";
}

bool ResourceFormatLoaderSpineAtlas::handles_type(const String &p_type) const {
    return ClassDB::is_parent_class(p_type, "Resource");
}