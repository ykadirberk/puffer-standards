#include <iostream>

#include "include/pufd/String/String.h"

int main()
{
    pufd::String str = "LETSGO";
    pufd::String newstring = str.clone().fast_result();

    std::cout << "Hello, World!" << std::endl;
    std::cout << "MyString ::: " << newstring << std::endl;
    std::cout << "Addresses : " << std::endl
              << "str : " << &str << std::endl
			  << "newstring : " << &newstring << std::endl;
    return 0;
}
