//
// Created by Raymond_Lx on 2020/6/2.
//

#ifndef GODOT_SPINEATLASRESOURCEMAP_H
#define GODOT_SPINEATLASRESOURCEMAP_H

#include <scene/resources/texture.h>


struct SpineAtlasResourceMap {
    Ref<ImageTexture> *p_tex;
    Ref<ImageTexture> *p_normal_tex;    
};


#endif //GODOT_SPINEATLASRESOURCE_H
