//
// Created by ykadi on 21.08.2024.
//

#ifndef ARRAY_H
#define ARRAY_H

// internal dependencies
#include "../Utils/NumericalTypes.h"
#include "../Allocators/BasicAllocator.h"

namespace pufd
{
	template<typename Type>
	class Array {
		public:
			Array(Allocator& allocator = basic_allocator) : allocator(allocator)
			{
				auto allocation_result = allocator.allocate(sizeof(Type) * 15);

				if (true == allocation_result.is_successful())
				{
					auto allocation = allocation_result.extract_success();
					Pointer<Type> type_pointer = static_cast<Type*>(allocation.extract_pointer());
					data = pufd::move(type_pointer);

				}

			}

		private:
			Pointer<Type> data;
			Allocator& allocator;
			u64 current_size;
			u64 allocated_size;
	};
}




#endif //ARRAY_H
