#include "a.h"
#include <iostream>



int main()
{
    std::string text_1 = "Hello Word\nand others planets";
    A example_1(text_1);
    std::cout << example_1.get() << "\n\n";
    A example_2(example_1);
    std::cout << example_2.get() << "\n\n";
    A example_3(std::move(A("Something...to check")));
    std::cout << example_3.get() << "\n";
    return 0;
}

