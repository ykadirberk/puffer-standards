//
// Created by ykadi on 11.08.2024.
//

#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <malloc.h>

// internal dependencies
#include "../Utils/Result.h"
#include "../SmartPointers/Pointer.h"
#include "../SmartPointers/SharedPointer.h"
#include "../Utils/NumericalTypes.h"

namespace pufd
{
    class Allocator
    {
        public:
            Allocator() = default;
            virtual ~Allocator() = default;

            auto virtual allocate(size_t size) -> pufd::Result<pufd::Pointer<u8>, const char*> = 0;
    };
}

#endif //ALLOCATOR_H
