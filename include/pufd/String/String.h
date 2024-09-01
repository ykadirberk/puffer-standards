//
// Created by ykadi on 11.08.2024.
//

#ifndef STRING_H
#define STRING_H

#include <ostream>

#include "../Allocators/BasicAllocator.h"
#include "../SmartPointers/Pointer.h"
#include "../Utils/Cloneable.h"

namespace pufd
{
    class String : public Cloneable<pufd::String, const char*>
    {
        public:
            String(Allocator& allocator = basic_allocator); // NOLINT(*-explicit-constructor)

            ~String() override;

            // implicit converter
            String(const char* str); // NOLINT(*-explicit-constructor)

            String(const pufd::String& other) = delete; // copy constructor deleted

            String(pufd::String&& other) noexcept;

            auto operator=(pufd::String&& other) noexcept -> pufd::String&;

            auto operator=(const pufd::String& other) -> pufd::String& = delete; // copy assignment deleted


            [[nodiscard]] auto clone() const -> Result<pufd::String, const char*> override;

            [[nodiscard]] auto size() const noexcept -> size_t;

            [[nodiscard]] auto length() const noexcept -> size_t;

            friend inline std::ostream& operator<<(std::ostream& os, const String& obj);

        private:
            Allocator& allocator;
            Pointer<char> data = nullptr;
            size_t current_size;
            size_t reserved_size;

            // helper functions
            static auto cstring_size(const char* str) -> size_t;
            static auto cstring_length(const char* str) -> size_t;
    };
    inline std::ostream& operator<<(std::ostream& os, const String& obj)
    {
        // if (nullptr != obj.data)
        // {
            os.write(static_cast<const char*>(&obj.data[0]), static_cast<std::streamsize>(obj.size()));
            return os;
        // }
        // else
        // {
        //     throw std::runtime_error("String object is moved out of scope.");
        // }
    }
}

#endif //STRING_H
