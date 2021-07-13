//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineSkeletonJsonDataResource.h"


void SpineSkeletonJsonDataResource::_bind_methods() {
}

Error SpineSkeletonJsonDataResource::load_from_file(const String &p_path) {
    Error err;

    json_string = FileAccess::get_file_as_string(p_path, &err);
    return err;
}

Error SpineSkeletonJsonDataResource::save_to_file(const String &p_path) {
    Error err;
    FileAccess *file = FileAccess::open(p_path, FileAccess::WRITE, &err);
    if (err != OK) {
        if (file) file->close();
        return err;
    }

    file->store_string(json_string);
    file->close();

    return OK;
}
