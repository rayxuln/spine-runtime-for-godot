//
// Created by Raiix on 2021/7/13.
//

#ifdef TOOLS_ENABLED
#include "SpineRuntimeEditorPlugin.h"

#include "SpineAtlasResource.h"
#include "SpineSkeletonJsonDataResource.h"

Error SpineAtlasResourceImportPlugin::import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata){
    Ref<SpineAtlasResource> res(memnew(SpineAtlasResource));
    res->set_normal_texture_prefix(p_options["normal_texture_prefix"]);
    res->load_from_atlas_file(p_source_file);

    String file_name = vformat("%s.%s", p_save_path, get_save_extension());
    auto err = ResourceSaver::save(file_name, res);
    return err;
}

void SpineAtlasResourceImportPlugin::get_import_options(List<ImportOption> *r_options, int p_preset) const {
    if (p_preset == 0) {
        ImportOption op;
        op.option.name = "normal_texture_prefix";
        op.option.type = Variant::STRING;
        op.option.hint_string = "String";
        op.default_value = String("n");
        r_options->push_back(op);
    }
}

Error SpineJsonResourceImportPlugin::import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata){
    Ref<SpineSkeletonJsonDataResource> res(memnew(SpineSkeletonJsonDataResource));
    res->load_from_file(p_source_file);

    String file_name = vformat("%s.%s", p_save_path, get_save_extension());
    auto err = ResourceSaver::save(file_name, res);
    return err;
}

SpineRuntimeEditorPlugin::SpineRuntimeEditorPlugin(EditorNode *p_node) {
    add_import_plugin(memnew(SpineAtlasResourceImportPlugin));
    add_import_plugin(memnew(SpineJsonResourceImportPlugin));
}



#endif