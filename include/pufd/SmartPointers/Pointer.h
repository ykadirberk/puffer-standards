//
// Created by ykadi on 11.08.2024.
//

#ifndef POINTER_H
#define POINTER_H

// internal dependencies
#include "../Utils/Move.h"

namespace pufd
{
    // A class that holds the ownership of a pointer.
    // That pointer will be deleted if the instance is out of scope.
    template <typename Type>
    class Pointer
    {
        public:
            Pointer() = delete;
            Pointer(Type* pointer = nullptr) noexcept : data(pufd::move(pointer)) // NOLINT(*-explicit-constructor)
            {
            }

            ~Pointer()
            {
                if (nullptr != data)
                {
                    delete data;
                    data = nullptr;
                }
            }

            Pointer(const Pointer& other) = delete; // cannot copy
            Pointer(Pointer<Type>&& other) noexcept : data(other.data)
            {
                other.data = nullptr;
            }

            auto operator=(const Pointer& other) -> Pointer& = delete; // cannot copy
            auto operator=(Pointer<Type>&& other) noexcept -> Pointer&
            {
                this->data = other.data;
                other.data = nullptr;
                return *this;
            }

            auto operator=(void* ptr) noexcept -> Pointer&
            {
                this->data = static_cast<Type*>(ptr);
                return *this;
            }

            auto operator[](size_t index) -> Type&
            {
                if (nullptr == data)
                {
                    throw std::runtime_error("NULLPTR exception");
                }
                return data[index];
            }

            auto operator[](size_t index) const -> const Type&
            {
                if (nullptr == data)
                {
                    throw std::runtime_error("NULLPTR exception");
                }
                return data[index];
            }

            auto operator*() -> Type&
            {
                return *data;
            }

            auto operator->() -> Type&
            {
                return *data;
            }

            auto operator==(Type* pointer) const noexcept -> bool
            {
                bool result = false;
                if (data == pointer)
                {
                    result = true;
                }
                else
                {
                    result = false;
                }
                return result;
            }

            // returns the C pointer and takes its ownership.
            auto extract_pointer() -> Type*
            {
                Type* temp = data;
                data = nullptr;
                return temp;
            }
        private:
            Type* data;
    };
}

#endif //POINTER_H
