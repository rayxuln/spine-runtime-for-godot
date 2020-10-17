//
// Created by Raymond_Lx on 2020/6/2.
//

#include "RaiixSpineExtension.h"

#include "core/variant_parser.h"
#include <spine/SpineString.h>

#include <iostream>

spine::SpineExtension *spine::getDefaultExtension() {
    return new RaiixSpineExtension();
}

RaiixSpineExtension::RaiixSpineExtension(){}
RaiixSpineExtension::~RaiixSpineExtension(){}

void *RaiixSpineExtension::_alloc(size_t size, const char *file, int line){
//	std::cout<<"_alloc "<<file<<" "<<line<<std::endl;
    return memalloc(size);
}

void *RaiixSpineExtension::_calloc(size_t size, const char *file, int line){
//	std::cout<<"_calloc "<<file<<" "<<line<<std::endl;
    auto p = memalloc(size);
    memset(p, 0, size);
    return p;
}

void *RaiixSpineExtension::_realloc(void *ptr, size_t size, const char *file, int line){
//	std::cout<<"_realloc "<<file<<" "<<line<<std::endl;
    return memrealloc(ptr, size);
}

void RaiixSpineExtension::_free(void *mem, const char *file, int line){
//	std::cout<<"_free "<<file<<" "<<line<<std::endl;
    memfree(mem);
}

char *RaiixSpineExtension::_readFile(const spine::String &path, int *length){
    Error error;
    auto res = FileAccess::get_file_as_array(String(path.buffer()), &error);
//    std::cout<<"Spine is loading something: "<<path.buffer()<<std::endl;
    if (error != OK){
        if(length) *length = 0;
        return NULL;
    }

    if(length) *length = res.size();
    auto r = alloc<char>(res.size(), __FILE__, __LINE__);
    for(size_t i=0;i<res.size();++i)
        r[i] = res[i];
    return r;
}