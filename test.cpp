#include <iostream>

#include "include/pufd/String/String.h"

int main()
{
    pufd::string str = "Hello, World!";
    std::cout << "str :: " << str << std::endl;

    pufd::string newstring = str.clone().fast_result();
    std::cout << "newstring :: " << newstring << std::endl;

    pufd::string moved = pufd::move(str);
    std::cout << "moved :: " << moved << std::endl;
    std::cout << "str(moved) :: " << str << std::endl;

    return 0;
}
