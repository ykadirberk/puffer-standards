//
// Created by ykadi on 11.08.2024.
//

#ifndef BASICALLOCATOR_H
#define BASICALLOCATOR_H

#include "Allocator.h"
#include "../Utils/NumericalTypes.h"

namespace pufd
{
    inline class BasicAllocator : public Allocator
    {
        public:
            BasicAllocator() = default;

            ~BasicAllocator() override = default;

            auto allocate(size_t size) -> pufd::Result<Pointer<u8>, const char*> override;
    } basic_allocator;
}

#endif //BASICALLOCATOR_H
