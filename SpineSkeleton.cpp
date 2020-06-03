//
// Created by Raymond_Lx on 2020/6/3.
//

#include "SpineSkeleton.h"

void SpineSkeleton::_bind_methods() {

}

SpineSkeleton::SpineSkeleton():skeleton(NULL) {

}

SpineSkeleton::~SpineSkeleton() {
	if(skeleton)
	{
		delete skeleton;
		skeleton = NULL;
	}
}