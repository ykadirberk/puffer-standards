cmake_minimum_required(VERSION 3.28)
project(puffer_standards)

set(CMAKE_CXX_STANDARD 20)

add_executable(puffer_standards test.cpp
        include/pufd/Allocators/BasicAllocator.h
        include/pufd/Allocators/Allocator.h
        include/pufd/Utils/Result.h
        include/pufd/String/String.h
        include/pufd/SmartPointers/Pointer.h
        include/pufd/SmartPointers/SharedPointer.h
        include/pufd/Utils/Move.h
        source/BasicAllocator.cpp
        source/String.cpp
        include/pufd/Utils/Cloneable.h
        source/Array.cpp
        include/pufd/Containers/Array.h
        include/pufd/Utils/NumericalTypes.h
)
