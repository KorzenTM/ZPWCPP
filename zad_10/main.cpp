#include "a.h"
#include <iostream>

template<typename T>
A copy(T&& object);

int main()
{
    std::string text_1 = "Hello Word\nand others planets";
    A example_1(text_1);
    std::cout << example_1.get() << "\n\n";
    A example_2 = copy(example_1);
    std::cout << example_2.get() << "\n\n";
    auto &&r = A("Something");
    A example_3 = copy(std::move(r));
    std::cout << example_3.get() << "\n";
    return 0;
}

template<typename T>
A copy(T&& object)
{
    return A(std::forward<T>(object));
}
