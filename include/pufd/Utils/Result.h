//
// Created by ykadi on 11.08.2024.
//

#ifndef RESULT_H
#define RESULT_H

#include <variant>
#include <stdexcept>

// internal dependencies
#include "Move.h"

namespace pufd
{

    template <typename SuccessType, typename ErrorType>
    class Result
    {
        public:
            Result() = delete;
            Result(const Result<SuccessType, ErrorType>& other) = delete;
            Result(Result<SuccessType, ErrorType>&& other) noexcept // NOLINT(*-pro-type-member-init)
            {
                this->success = other.success;
                this->result = pufd::move(other.result);
            }
            auto operator=(Result<SuccessType, ErrorType>&& other) noexcept -> Result<SuccessType, ErrorType>&
            {
                this->success = other.success;
                this->result = pufd::move(other.result);
                return *this;
            }

            Result(SuccessType&& success_val) noexcept : result(pufd::move(success_val)), success(true) // NOLINT(*-explicit-constructor)
            {
            }
            Result(ErrorType&& error) noexcept : result(std::forward<ErrorType>(error)), success(false) // NOLINT(*-explicit-constructor)
            {
            }

            [[nodiscard]] auto is_successful() const noexcept -> bool
            {
                return success;
            }

            [[nodiscard]] auto extract_success() -> SuccessType&&
            {
                return pufd::move(std::get<0>(result));
            }

            [[nodiscard]] auto get_error() -> ErrorType
            {
                return std::get<1>(result);
            }

            [[nodiscard]] auto fast_result() -> SuccessType&&
            {
                if (true == success)
                {
                    return extract_success();
                }
                else
                {
                    throw std::runtime_error("EXCEPTION:: Error occured but it was not handled.\n");
                }
            }
        private:
            bool success;
            std::variant<SuccessType, ErrorType> result;
    };
}

#endif //RESULT_H
