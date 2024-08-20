//
// Created by ykadi on 20.08.2024.
//

#include "../include/pufd/Allocators/BasicAllocator.h"

namespace pufd
{
	auto BasicAllocator::allocate(size_t size) -> pufd::Result<Pointer<uint8_t>, const char *>
	{
		auto* pointer = (uint8_t*)malloc(size);
		if (nullptr != pointer)
		{
			return pufd::Pointer(pointer);
		}
		else
		{
			return "Error while allocating, using BasicAllocator.";
		}
	}
}

