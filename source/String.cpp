//
// Created by ykadi on 20.08.2024.
//

#include "../include/pufd/String/String.h"
namespace pufd
{
	String::String(Allocator& allocator) : allocator(allocator)
	{
		current_size = 0;
		reserved_size = 0;
	}

	String::~String()
	{
			// destructor
	}

	String::String(const char* str) : allocator(basic_allocator)
	{
		size_t size_of_str = cstring_size(str);
		auto allocation_result = allocator.allocate(size_of_str);

		if (true == allocation_result.is_successful())
		{
			auto allocation = allocation_result.extract_success();
			Pointer<char> pointer_char = (char*)(allocation.extract_pointer());
			data = pufd::move(pointer_char);

			for (int i = 0; i < size_of_str; i++)
			{
				data[i] = str[i];
			}
			current_size = size_of_str;
			reserved_size = size_of_str;
		}
		else
		{
			current_size = 0;
			reserved_size = 0;
		}
	}

	String::String(pufd::String&& other) noexcept : allocator(other.allocator)
	{
		this->current_size = other.current_size;
		this->data = pufd::move(other.data);
		this->reserved_size = other.reserved_size;
		other.data = nullptr;
	}

	auto String::operator=(pufd::String&& other) noexcept -> pufd::String& // move assignment
	{
		this->allocator = other.allocator;
		this->current_size = other.current_size;
		this->data = pufd::move(other.data);
		this->reserved_size = other.reserved_size;
		other.data = nullptr;

		return *this;
	}

	auto String::clone() const -> Result<pufd::String, const char*>
	{
		String temp(this->allocator);
		auto allocation_result = allocator.allocate(this->size());

		if (true == allocation_result.is_successful())
		{
			auto allocation = allocation_result.extract_success();
			Pointer<char> pointer_char = (char*)(allocation.extract_pointer());
			temp.data = pufd::move(pointer_char);
			memcpy(&temp.data[0], &this->data[0], this->size());

			temp.current_size = this->current_size;
			temp.reserved_size = this->reserved_size;
		} else
		{
			return "Could not clone String: allocation error.";
		}
		return temp;
	}

	auto String::size() const noexcept -> size_t
	{
		return current_size;
	}

	auto String::length() const noexcept -> size_t
	{
		return current_size == 1 ? 0 : current_size - 1;
	}

	auto String::cstring_size(const char* str) -> size_t
	{
		size_t size;
		for (size_t i = 0; ; i++)
		{
			if (str[i] == '\0')
			{
				size = i + 1;
				break;
			}
		}
		return size;
	}

	auto String::cstring_length(const char* str) -> size_t
	{
		const size_t size = cstring_size(str);
		size_t result = 0;
		if (0 != size)
		{
			result = size - 1;
		}
		else
		{
			result = 0;
		}
		return result;
	}

}
