//
// Created by ykadi on 11.08.2024.
//

#ifndef MOVE_H
#define MOVE_H

namespace pufd
{
	// cppreference implementation of move semantics

	template<class T> struct remove_reference { typedef T type; };
	template<class T> struct remove_reference<T&> { typedef T type; };
	template<class T> struct remove_reference<T&&> { typedef T type; };


	template <typename Type>
	constexpr auto move(Type&& type) -> typename remove_reference<Type>::type&&
	{
		return static_cast<typename std::remove_reference<Type>::type&&>(type);
	}

	template <typename Type>
	constexpr auto forward(typename remove_reference<Type>::type& type) noexcept -> Type&&
	{
		return static_cast<typename remove_reference<Type>::type&>(type);
	}

	template <typename Type>
	constexpr auto forward(typename remove_reference<Type>::type&& type) noexcept -> Type&&
	{
		return static_cast<typename remove_reference<Type>::type&&>(type);
	}
}

#endif //MOVE_H
