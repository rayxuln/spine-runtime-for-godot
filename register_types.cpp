
#include "register_types.h"

#include "core/class_db.h"

#include "spine_runtime.h"
#include "SpineAtlasResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "SpineSkeletonDataResource.h"
#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "SpineSprite.h"
#include "SpineAnimationStateDataResource.h"
#include "SpineSkeleton.h"
#include "SpineAnimationState.h"


static Ref<ResourceFormatLoaderSpineAtlas> atlas_loader;
static Ref<ResourceFormatLoaderSpineSkeletonJsonData> json_skeleton_loader;

void register_spine_runtime_types(){
    ClassDB::register_class<SpineRuntime>();
    ClassDB::register_class<SpineAtlasResource>();
    ClassDB::register_class<SpineSprite>();
	ClassDB::register_class<SpineSkeletonDataResource>();
	ClassDB::register_class<SpineAnimationStateDataResource>();
	ClassDB::register_class<SpineSkeletonJsonDataResource>();
	ClassDB::register_class<SpineSkeleton>();
	ClassDB::register_class<SpineAnimationState>();
	ClassDB::register_class<SpineAnimation>();

    atlas_loader.instance();
    ResourceLoader::add_resource_format_loader(atlas_loader);

	json_skeleton_loader.instance();
	ResourceLoader::add_resource_format_loader(json_skeleton_loader);

}

void unregister_spine_runtime_types(){
    ResourceLoader::remove_resource_format_loader(atlas_loader);
    atlas_loader.unref();

	ResourceLoader::remove_resource_format_loader(json_skeleton_loader);
	json_skeleton_loader.unref();
}