//
// Created by Raymond_Lx on 2020/6/2.
//

#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "SpineSkeletonJsonDataResource.h"

RES ResourceFormatLoaderSpineSkeletonJsonData::load(const String &p_path, const String &p_original_path, Error *r_error) {
    Ref<SpineSkeletonJsonDataResource> skeleton = memnew(SpineSkeletonJsonDataResource);
    skeleton->load_from_file(p_path);

    if(r_error){
        *r_error = OK;
    }
    return skeleton;
}

void ResourceFormatLoaderSpineSkeletonJsonData::get_recognized_extensions(List<String> *r_extensions) const {
    const char json_ext[] = "spjson";
    if(!r_extensions->find(json_ext)) {
        r_extensions->push_back(json_ext);
    }
}

String ResourceFormatLoaderSpineSkeletonJsonData::get_resource_type(const String &p_path) const {
    return "SpineSkeletonJsonDataResource";
}

bool ResourceFormatLoaderSpineSkeletonJsonData::handles_type(const String &p_type) const {
    return p_type == "SpineSkeletonJsonDataResource" || ClassDB::is_parent_class(p_type, "SpineSkeletonJsonDataResource");
}