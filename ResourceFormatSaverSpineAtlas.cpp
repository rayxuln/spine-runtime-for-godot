//
// Created by Raiix on 2021/7/13.
//

#include "ResourceFormatSaverSpineAtlas.h"

#include "SpineAtlasResource.h"

Error ResourceFormatSaverSpineAtlas::save(const String &p_path, const RES &p_resource, uint32_t p_flags) {
    Ref<SpineAtlasResource> res = p_resource.get_ref_ptr();
    Error error = res->save_to_file(p_path);
    return error;
}

void ResourceFormatSaverSpineAtlas::get_recognized_extensions(const RES &p_resource, List<String> *p_extensions) const {
    if (Object::cast_to<SpineAtlasResource>(*p_resource)) {
        p_extensions->push_back("spatlas");
    }
}

bool ResourceFormatSaverSpineAtlas::recognize(const RES &p_resource) const {
    return Object::cast_to<SpineAtlasResource>(*p_resource) != nullptr;
}
