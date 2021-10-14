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
    ClassDB::bind_method(D_METHOD("get_frame_entries"), &SpineTimeline::get_frame_entries);
    ClassDB::bind_method(D_METHOD("get_frame_count"), &SpineTimeline::get_frame_count);
    ClassDB::bind_method(D_METHOD("get_frames"), &SpineTimeline::get_frames);
    ClassDB::bind_method(D_METHOD("get_duration"), &SpineTimeline::get_duration);
    ClassDB::bind_method(D_METHOD("getPropertyIds"), &SpineTimeline::getPropertyIds);
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

int64_t SpineTimeline::get_frame_entries() {
    return timeline->getFrameEntries();
}

int64_t SpineTimeline::get_frame_count() {
    return timeline->getFrameCount();
}

Array SpineTimeline::get_frames() {
    auto &frames = timeline->getFrames();
    Array res;
    res.resize(frames.size());

    for (size_t i=0; i<res.size(); ++i) {
        res[i] = frames[i];
    }

    return res;
}

float SpineTimeline::get_duration() {
    return timeline->getDuration();
}

Array SpineTimeline::getPropertyIds() {
    auto &ids = timeline->getPropertyIds();
    Array res;
    res.resize(ids.size());

    for (size_t i=0; i<res.size(); ++i) {
        res[i] = (int64_t)ids[i];
    }

    return res;
}


