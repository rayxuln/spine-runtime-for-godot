//
// Created by Raiix on 2021/7/16.
//

#ifndef GODOT_SPINESPRITEANIMATEDIALOG_H
#define GODOT_SPINESPRITEANIMATEDIALOG_H

#ifdef TOOLS_ENABLED
#include "editor/editor_node.h"

class SpineSprite;

class SpineSpriteAnimateDialog : public Control {
    GDCLASS(SpineSpriteAnimateDialog, Control);

protected:
    static void _bind_methods();

    AcceptDialog *error_dialog;

    ToolButton *animate_button;
    EditorPlugin *the_plugin;

    ConfirmationDialog *animate_dialog;
    Button *animate_dialog_override_button;
    Tree *animate_dialog_tree;
    SceneTreeDialog *scene_tree_dialog;

    NodePath spine_sprite_path;
    NodePath anim_player_path;

    void add_row(const String &animation, bool loop=true, int64_t track_id=0);
    void clear_tree();

    void error(const String &text, const String &title="Error");

    void load_data_from_sprite(SpineSprite *sprite, bool &err);
    void load_data_from_anim_player(AnimationPlayer *anim_player, bool &err);

    Dictionary get_data_from_tree();

    void gen_new_animation_player(SpineSprite *sprite, bool &err);
    void gen_animations(SpineSprite *sprite, AnimationPlayer *anim_player, const Dictionary &config, float min_duration, bool &err);
    Dictionary gen_current_animation_data(const String &animation, int64_t track_id, bool loop, bool clear, bool empty, bool empty_duration, float delay);
public:
    SpineSpriteAnimateDialog();
    ~SpineSpriteAnimateDialog();

    void set_animate_button(ToolButton *b);
    inline ToolButton *get_animate_button() {return animate_button;}

    inline void set_plugin(EditorPlugin *p) {the_plugin = p;}

    void _on_animate_button_pressed();
    void _on_scene_tree_selected(NodePath path);
    void _on_scene_tree_hide();
    void _on_animate_dialog_action(const String &act);
};
#endif

#endif //GODOT_SPINESPRITEANIMATEDIALOG_H
