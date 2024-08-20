// //
// // Created by ykadi on 11.08.2024.
// //
//
// #ifndef SHAREDPOINTER_H
// #define SHAREDPOINTER_H
//
// #include <cstdint>
// #include <atomic>
//
// // internal dependencies
// #include <ranges>
//
// #include "Pointer.h"
// #include "../Allocators/BasicAllocator.h"
//
//
//
// namespace pufd
// {
// 	template <typename Type>
// 	class SharedPointer
// 	{
// 		using RefCounterNumericType = uint32_t;
// 		using AtomicRefCounter = std::atomic<RefCounterNumericType>;
//
// 		public:
// 			SharedPointer(Type* pointer, Allocator& allocator = basic_allocator) : allocator(allocator) // NOLINT(*-explicit-constructor)
// 			{
// 				data = pointer;
// 				auto ref_count_allocation_result = allocator.new_variable<AtomicRefCounter>();
// 				if (true == ref_count_allocation_result.is_successful())
// 				{
// 					auto ref_count_allocation = ref_count_allocation_result.extract_success();
// 					ref_count = ref_count_allocation.extract_pointer();
// 					*ref_count = 1;
// 				}
// 			}
//
// 			~SharedPointer()
// 			{
// 				RefCounterNumericType current_ref_count, intended_ref_count;
//
// 				do
// 				{
// 					current_ref_count = ref_count->load(std::memory_order_acquire);
// 					intended_ref_count = current_ref_count - 1;
// 				} while(false == ref_count->compare_exchange_strong(&current_ref_count, intended_ref_count, std::memory_order_acq_rel));
//
// 				if (0 == ref_count)
// 				{
// 					delete data;
// 					delete ref_count;
// 				}
// 			}
//
//
//
// 		private:
// 			Allocator& allocator;
// 			Type* data;
// 			AtomicRefCounter* ref_count;
// 	};
//
// 	template<typename Type>
// 	template<typename ... Args>
// 	auto SharedPointer<Type>::build(Args&&... args) -> SharedPointer<Type>
// 	{
// 		auto allocation_result = allocator.new_variable<Type>();
//
// 	}
// }
//
// #endif //SHAREDPOINTER_H
