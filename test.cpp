#include <iostream>

#include "include/pufd/String/String.h"

int main()
{
    pufd::String str = "Hello, World!";
    std::cout << "str :: " << str << std::endl;

    pufd::String newstring = str.clone().fast_result();
    std::cout << "newstring :: " << newstring << std::endl;

    pufd::String moved = pufd::move(str);
    std::cout << "moved :: " << moved << std::endl;
    std::cout << "str(moved) :: " << str << std::endl;

    return 0;
}
