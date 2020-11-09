#include "a.h"
#include <iostream>

A copy(const A &object);
A copy(A&& object);

int main()
{
    std::string text_1 = "Hello Word\nand others planets";
    A example_1(text_1);
    std::cout << example_1.get() << "\n\n";
    A example_2 = copy(example_1);
    std::cout << example_2.get() << "\n\n";
    A example_3 = copy(std::move(A("Something...to check")));
    std::cout << example_3.get() << "\n";
    return 0;
}

A copy(const A &object)
{
    return A(object);
}

A copy(A&& object)
{
    return A(std::move(object));
}
