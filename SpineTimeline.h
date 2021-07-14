//
// Created by Raiix on 2021/7/14.
//

#ifndef GODOT_SPINETIMELINE_H
#define GODOT_SPINETIMELINE_H

#include "core/variant_parser.h"

#include "spine/Timeline.h"

class SpineTimeline : public Reference{
    GDCLASS(SpineTimeline, Reference);
private:
    spine::Timeline *timeline;
public:
    SpineTimeline();
    ~SpineTimeline();

    inline void set_spine_object(spine::Timeline *v) {timeline = v;}
    inline spine::Timeline *get_spine_object() {return timeline;}


};


#endif //GODOT_SPINETIMELINE_H
