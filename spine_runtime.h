
#ifndef _GODOT_RAIIX_SPINE_RUNTIME_
#define _GODOT_RAIIX_SPINE_RUNTIME_

#include "core/reference.h"

class SpineRuntime : public Reference {
    GDCLASS(SpineRuntime, Reference);

protected:
    static void _bind_methods();

public:
    void hi();

    SpineRuntime();
};

#endif