//
// Created by ykadi on 11.08.2024.
//

#ifndef MOVE_H
#define MOVE_H

namespace pufd
{
	template <typename Type>
	auto move(Type& type) -> Type&&
	{
		return static_cast<Type&&>(type);
	}
}

#endif //MOVE_H
