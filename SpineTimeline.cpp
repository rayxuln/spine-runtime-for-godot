//
// Created by Raiix on 2021/7/14.
//

#include "SpineTimeline.h"

#include "SpineSkeleton.h"
#include "SpineEvent.h"

// enable more than 5 arguments of a method bind function
#include "core/method_bind_ext.gen.inc"

void SpineTimeline::_bind_methods() {
    ClassDB::bind_method(D_METHOD("apply", "skeleton", "lastTime", "time", "pEvents", "alpha", "blend", "direction"), &SpineTimeline::apply);
    ClassDB::bind_method(D_METHOD("getPropertyId"), &SpineTimeline::getPropertyId);
}


SpineTimeline::SpineTimeline():timeline(nullptr) {

}

SpineTimeline::~SpineTimeline() {

}

void SpineTimeline::apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, Array pEvents, float alpha,
                          SpineConstant::MixBlend blend, SpineConstant::MixDirection direction) {
    spine::Vector<spine::Event*> events;
    events.setSize(pEvents.size(), nullptr);
    for (size_t i=0; i<events.size(); ++i) {
        events[i] = ((Ref<SpineEvent>)pEvents[i])->get_spine_object();
    }

    timeline->apply(*(skeleton->get_spine_object()), lastTime, time, &events, alpha, (spine::MixBlend) blend, (spine::MixDirection) direction);
}

int SpineTimeline::getPropertyId() {
    return timeline->getPropertyId();
}


