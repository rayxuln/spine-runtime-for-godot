//
// Created by Raiix on 2021/7/14.
//

#include "SpineConstant.h"

void SpineConstant::_bind_methods() {
    BIND_ENUM_CONSTANT(MixBlend_Setup);
    BIND_ENUM_CONSTANT(MixBlend_First);
    BIND_ENUM_CONSTANT(MixBlend_Replace);
    BIND_ENUM_CONSTANT(MixBlend_Add);

    BIND_ENUM_CONSTANT(MixDirection_In);
    BIND_ENUM_CONSTANT(MixDirection_Out);

    BIND_ENUM_CONSTANT(Property_Rotate);
    BIND_ENUM_CONSTANT(Property_X);
    BIND_ENUM_CONSTANT(Property_Y);
    BIND_ENUM_CONSTANT(Property_ScaleX);
    BIND_ENUM_CONSTANT( Property_ScaleY);
    BIND_ENUM_CONSTANT(Property_ShearX);
    BIND_ENUM_CONSTANT(Property_ShearY);
    BIND_ENUM_CONSTANT(Property_Rgb);
    BIND_ENUM_CONSTANT(Property_Alpha);
    BIND_ENUM_CONSTANT(Property_Rgb2);
    BIND_ENUM_CONSTANT(Property_Attachment);
    BIND_ENUM_CONSTANT(Property_Deform);
    BIND_ENUM_CONSTANT(Property_Event);
    BIND_ENUM_CONSTANT(Property_DrawOrder);
    BIND_ENUM_CONSTANT(Property_IkConstraint);
    BIND_ENUM_CONSTANT(Property_TransformConstraint);
    BIND_ENUM_CONSTANT(Property_PathConstraintPosition);
    BIND_ENUM_CONSTANT(Property_PathConstraintSpacing);
    BIND_ENUM_CONSTANT(Property_PathConstraintMix);


}