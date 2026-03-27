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
    class string
    {
        public:
            string();

            ~string();

            string(const char* str);

            string(const pufd::string& other) = delete; 

            string(pufd::string&& other) noexcept;

            auto operator=(pufd::string&& other) noexcept -> pufd::string&;

            auto operator=(const pufd::string& other) -> pufd::string& = delete;


            [[nodiscard]] auto clone() const -> pufd::string;

            [[nodiscard]] auto size() const noexcept -> size_t;

            [[nodiscard]] auto length() const noexcept -> size_t;

            friend inline std::ostream& operator<<(std::ostream& os, const string& obj);

            u64 current_size;
            u64 reserved_size;

            // helper functions
            static auto cstring_size(const char* str) -> size_t;
            static auto cstring_length(const char* str) -> size_t;
    };
    inline std::ostream& operator<<(std::ostream& os, const string& obj)
    {
        // if (nullptr != obj.data)
        // {
        //  os.write(static_cast<const char*>(&obj.data[0]), static_cast<std::streamsize>(obj.size()));
        //  return os;
        // }
        // else
        // {
        //     throw std::runtime_error("String object is moved out of scope.");
        // }
    }
}

#endif //STRING_H
