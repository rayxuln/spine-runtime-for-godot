
#include "register_types.h"

#include "core/class_db.h"

#include "spine_runtime.h"
#include "SpineAtlasResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineSprite.h"

static Ref<ResourceFormatLoaderSpineAtlas> atlas_loader;

void register_spine_runtime_types(){
    ClassDB::register_class<SpineRuntime>();
    ClassDB::register_class<SpineAtlasResource>();
    ClassDB::register_class<SpineSprite>();

    atlas_loader.instance();
    ResourceLoader::add_resource_format_loader(atlas_loader);
}

void unregister_spine_runtime_types(){
    ResourceLoader::remove_resource_format_loader(atlas_loader);
    atlas_loader.unref();
}