//
// Created by Raiix on 2021/7/13.
//

#ifndef GODOT_SPINERUNTIMEEDITORPLUGIN_H
#define GODOT_SPINERUNTIMEEDITORPLUGIN_H

#ifdef TOOLS_ENABLED
#include "editor/editor_node.h"

class SpineAtlasResourceImportPlugin : public EditorImportPlugin {
    GDCLASS(SpineAtlasResourceImportPlugin, EditorImportPlugin);

public:
    String get_importer_name() const override {return "raiix.spine_runtime.atlas";}
    String get_visible_name() const override {return "Spine Runtime Atlas";}
    void get_recognized_extensions(List<String> *p_extensions) const override {p_extensions->push_back("atlas");}
    String get_preset_name(int p_idx) const override {if (p_idx == 0) return "Default"; else return "Unknown";}
    int get_preset_count() const override {return 1;}
    String get_save_extension() const override {return "spatlas";}
    String get_resource_type() const override {return "SpineAtlasResource";}
    void get_import_options(List<ImportOption> *r_options, int p_preset) const override;
    bool get_option_visibility(const String &p_option, const Map<StringName, Variant> &p_options) const override {return true;}
    Error import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) override;
};

class SpineJsonResourceImportPlugin : public EditorImportPlugin {
GDCLASS(SpineJsonResourceImportPlugin, EditorImportPlugin);

public:
    String get_importer_name() const override {return "raiix.spine_runtime.json";}
    String get_visible_name() const override {return "Spine Runtime Json";}
    void get_recognized_extensions(List<String> *p_extensions) const override {p_extensions->push_back("json");}
    String get_preset_name(int p_idx) const override {if (p_idx == 0) return "Default"; else return "Unknown";}
    int get_preset_count() const override {return 1;}
    String get_save_extension() const override {return "spjson";}
    String get_resource_type() const override {return "SpineSkeletonJsonDataResource";}
    void get_import_options(List<ImportOption> *r_options, int p_preset) const override {}
    bool get_option_visibility(const String &p_option, const Map<StringName, Variant> &p_options) const override {return true;}
    Error import(const String &p_source_file, const String &p_save_path, const Map<StringName, Variant> &p_options, List<String> *r_platform_variants, List<String> *r_gen_files, Variant *r_metadata) override;
};

class SpineSpriteAnimateDialog;

class SpineRuntimeEditorPlugin : public EditorPlugin {
	GDCLASS(SpineRuntimeEditorPlugin, EditorPlugin);

protected:
    SpineSpriteAnimateDialog *animate_dialog;
public:
    SpineRuntimeEditorPlugin(EditorNode *p_node);
    ~SpineRuntimeEditorPlugin();

	String get_name() const override { return "SpineRuntimeEditorPlugin"; }
	bool has_main_screen() const { return false; }

	bool handles(Object *p_object) const override;
	void make_visible(bool p_visible) override;

	void _on_animate_button_pressed();
};
#endif

#endif //GODOT_SPINERUNTIMEEDITORPLUGIN_H
