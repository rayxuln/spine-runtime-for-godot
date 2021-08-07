//
// Created by Raiix on 2021/7/13.
//

#include "ResourceFormatSaverSpineSkeletonJsonData.h"

#include "SpineSkeletonJsonDataResource.h"

Error ResourceFormatSaverSpineSkeletonJsonData::save(const String &p_path, const RES &p_resource, uint32_t p_flags) {
    Ref<SpineSkeletonJsonDataResource> res = p_resource.get_ref_ptr();
    Error error = res->save_to_file(p_path);
    return error;
}

void ResourceFormatSaverSpineSkeletonJsonData::get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const {
    if (Object::cast_to<SpineSkeletonJsonDataResource>(*p_resource)) {
        p_extensions->push_back("spjson");
    }
}

bool ResourceFormatSaverSpineSkeletonJsonData::recognize(const RES &p_resource) const {
    return Object::cast_to<SpineSkeletonJsonDataResource>(*p_resource) != nullptr;
}
