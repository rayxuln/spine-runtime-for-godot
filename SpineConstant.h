//
// Created by Raiix on 2021/7/14.
//

#ifndef GODOT_SPINECONSTANT_H
#define GODOT_SPINECONSTANT_H

#include "core/variant_parser.h"

class SpineConstant : public Object{
    GDCLASS(SpineConstant, Object);

protected:
    static void _bind_methods();
public:
    enum MixBlend {
        MixBlend_Setup = 0,
        MixBlend_First,
        MixBlend_Replace,
        MixBlend_Add
    };

    enum MixDirection {
        MixDirection_In = 0,
        MixDirection_Out
    };

    enum PropertyId {
        Property_Rotate = 1 << 0,
        Property_X = 1 << 1,
        Property_Y = 1 << 2,
        Property_ScaleX = 1 << 3,
        Property_ScaleY = 1 << 4,
        Property_ShearX = 1 << 5,
        Property_ShearY = 1 << 6,
        Property_Rgb = 1 << 7,
        Property_Alpha = 1 << 8,
        Property_Rgb2 = 1 << 9,
        Property_Attachment = 1 << 10,
        Property_Deform = 1 << 11,
        Property_Event = 1 << 12,
        Property_DrawOrder = 1 << 13,
        Property_IkConstraint = 1 << 14,
        Property_TransformConstraint = 1 << 15,
        Property_PathConstraintPosition = 1 << 16,
        Property_PathConstraintSpacing = 1 << 17,
        Property_PathConstraintMix = 1 << 18
    };
};

VARIANT_ENUM_CAST(SpineConstant::MixBlend);
VARIANT_ENUM_CAST(SpineConstant::MixDirection);
VARIANT_ENUM_CAST(SpineConstant::PropertyId);

#endif //GODOT_SPINECONSTANT_H
