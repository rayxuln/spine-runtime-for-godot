//
// Created by Raymond_Lx on 2020/6/4.
//

#include "SpineAnimation.h"

#include "SpineSkeleton.h"
#include "SpineEvent.h"
#include "SpineTimeline.h"

// enable more than 5 arguments of a method bind function
#include "core/method_bind_ext.gen.inc"

void SpineAnimation::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_anim_name"), &SpineAnimation::get_anim_name);
	ClassDB::bind_method(D_METHOD("get_duration"), &SpineAnimation::get_duration);
	ClassDB::bind_method(D_METHOD("set_duration", "v"), &SpineAnimation::set_duration);

	ClassDB::bind_method(D_METHOD("apply", "skeleton", "last_time", "time", "loop", "events", "alpha", "blend", "direction"), &SpineAnimation::apply);
	ClassDB::bind_method(D_METHOD("get_timelines"), &SpineAnimation::get_timelines);
	ClassDB::bind_method(D_METHOD("has_timeline", "ids"), &SpineAnimation::has_timeline);
}

SpineAnimation::SpineAnimation():animation(NULL) {}
SpineAnimation::~SpineAnimation(){}

String SpineAnimation::get_anim_name() {
	return animation->getName().buffer();
}

float SpineAnimation::get_duration() {
	return animation->getDuration();
}
void SpineAnimation::set_duration(float v) {
	animation->setDuration(v);
}

void SpineAnimation::apply(Ref<SpineSkeleton> skeleton, float lastTime, float time, bool loop,
                           Array pEvents, float alpha, SpineConstant::MixBlend blend,
                           SpineConstant::MixDirection direction) {
    spine::Vector<spine::Event*> events;
    events.setSize(pEvents.size(), nullptr);
    for (size_t i=0; i<events.size(); ++i) {
        events[i] = ((Ref<SpineEvent>)(pEvents[i]))->get_spine_object();
    }
    animation->apply(*(skeleton->get_spine_object()), lastTime, time, loop, &events, alpha, (spine::MixBlend) blend, (spine::MixDirection) direction);
}

Array SpineAnimation::get_timelines() {
    auto &timelines = animation->getTimelines();
    Array res;
    res.resize(timelines.size());

    for (size_t i=0; i<res.size(); ++i) {
        auto a = Ref<SpineTimeline>(memnew(SpineTimeline));
        a->set_spine_object(timelines[i]);
        res.set(i, a);
    }

    return res;
}

bool SpineAnimation::has_timeline(Array ids) {
    spine::Vector<spine::PropertyId> list;
    list.setSize(ids.size(), 0);

    for (size_t i=0; i<list.size(); ++i) {
        list[i] = (int64_t)ids[i];
    }
    return animation->hasTimeline(list);
}
