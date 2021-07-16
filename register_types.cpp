
#include "register_types.h"

#include "core/class_db.h"

#include "spine_runtime.h"
#include "SpineAtlasResource.h"
#include "ResourceFormatLoaderSpineAtlas.h"
#include "ResourceFormatSaverSpineAtlas.h"
#include "SpineSkeletonDataResource.h"
#include "ResourceFormatLoaderSpineSkeletonJsonData.h"
#include "ResourceFormatSaverSpineSkeletonJsonData.h"
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
#include "SpineSpriteMeshInstance2D.h"
#include "PackedSpineSkinResource.h"
#include "SpineTimeline.h"
#include "SpineConstant.h"
#include "SpineCollisionShapeProxy.h"
#include "SpineSpriteAnimateDialog.h"


static Ref<ResourceFormatLoaderSpineAtlas> atlas_loader;
static Ref<ResourceFormatSaverSpineAtlas> atlas_saver;
static Ref<ResourceFormatLoaderSpineSkeletonJsonData> json_skeleton_loader;
static Ref<ResourceFormatSaverSpineSkeletonJsonData> json_skeleton_saver;

// editor plugin
#ifdef TOOLS_ENABLED
#include "editor/editor_export.h"
#include "editor/editor_node.h"

#include "SpineRuntimeEditorPlugin.h"

static void editor_init_callback() {
    EditorNode::get_singleton()->add_editor_plugin(memnew(SpineRuntimeEditorPlugin(EditorNode::get_singleton())));
}


#endif

void register_spine_runtime_types(){
#ifdef TOOLS_ENABLED
    ClassDB::register_class<SpineSpriteAnimateDialog>();

	EditorNode::add_init_callback(editor_init_callback);

#endif

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
	ClassDB::register_class<SpineSpriteMeshInstance2D>();
	ClassDB::register_class<PackedSpineSkinResource>();
	ClassDB::register_class<SpineTimeline>();
	ClassDB::register_class<SpineConstant>();
	ClassDB::register_class<SpineCollisionShapeProxy>();

    atlas_loader.instance();
    ResourceLoader::add_resource_format_loader(atlas_loader);

    atlas_saver.instance();
    ResourceSaver::add_resource_format_saver(atlas_saver);

	json_skeleton_loader.instance();
	ResourceLoader::add_resource_format_loader(json_skeleton_loader);

	json_skeleton_saver.instance();
	ResourceSaver::add_resource_format_saver(json_skeleton_saver);

}

void unregister_spine_runtime_types(){
    ResourceLoader::remove_resource_format_loader(atlas_loader);
    atlas_loader.unref();

    ResourceSaver::remove_resource_format_saver(atlas_saver);
    atlas_saver.unref();

	ResourceLoader::remove_resource_format_loader(json_skeleton_loader);
	json_skeleton_loader.unref();

	ResourceSaver::remove_resource_format_saver(json_skeleton_saver);
	json_skeleton_saver.unref();
}