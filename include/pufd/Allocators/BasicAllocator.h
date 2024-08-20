//
// Created by ykadi on 11.08.2024.
//

#ifndef BASICALLOCATOR_H
#define BASICALLOCATOR_H

#include "Allocator.h"

namespace pufd
{
    inline class BasicAllocator : public Allocator
    {
        public:
            BasicAllocator() = default;

            ~BasicAllocator() override = default;

            auto allocate(size_t size) -> pufd::Result<Pointer<uint8_t>, const char*> override;
    } basic_allocator;
}

#endif //BASICALLOCATOR_H
