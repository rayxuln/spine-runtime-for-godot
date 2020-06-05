
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
#include "SpineEventData.h"
#include "SpineEvent.h"
#include "SpineTrackEntry.h"
#include "SpineBoneData.h"
#include "SpineSlotData.h"
#include "SpineAttachment.h"
#include "SpineSkinAttachmentMapEntries.h"
#include "SpineConstraintData.h"
#include "SpineSkin.h"
#include "SpineIkConstraintData.h"
#include "SpineTransformConstraintData.h"
#include "SpinePathConstraintData.h"


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
	ClassDB::register_class<SpineEventData>();
	ClassDB::register_class<SpineTrackEntry>();
	ClassDB::register_class<SpineEvent>();
	ClassDB::register_class<SpineBoneData>();
	ClassDB::register_class<SpineSlotData>();
	ClassDB::register_class<SpineAttachment>();
	ClassDB::register_class<SpineSkinAttachmentMapEntry>();
	ClassDB::register_class<SpineSkinAttachmentMapEntries>();
	ClassDB::register_class<SpineConstraintData>();
	ClassDB::register_class<SpineSkin>();
	ClassDB::register_class<SpineIkConstraintData>();
	ClassDB::register_class<SpineTransformConstraintData>();
	ClassDB::register_class<SpinePathConstraintData>();
	ClassDB::register_class<SpineBone>();
	ClassDB::register_class<SpineSlot>();
	ClassDB::register_class<SpineIkConstraint>();
	ClassDB::register_class<SpinePathConstraint>();
	ClassDB::register_class<SpineTransformConstraint>();

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