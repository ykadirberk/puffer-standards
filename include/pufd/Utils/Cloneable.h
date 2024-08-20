//
// Created by ykadi on 20.08.2024.
//

#ifndef CLONEABLE_H
#define CLONEABLE_H

#include "Result.h"
#include "../Allocators/BasicAllocator.h"

namespace pufd
{
	template<typename Type, typename ErrorType>
	class Cloneable
	{
		public:
			virtual ~Cloneable() = default;
			virtual auto clone() const -> Result<Type, ErrorType> = 0;
	};
}

#endif //CLONEABLE_H
