#include "spine_runtime.h"

#include <iostream>

void SpineRuntime::hi(){
    std::cout<<"Hi im raiix!~ from spine runtime"<<std::endl;
}

void SpineRuntime::_bind_methods(){
    ClassDB::bind_method(D_METHOD("hi"), &SpineRuntime::hi);
}

SpineRuntime::SpineRuntime(){

}