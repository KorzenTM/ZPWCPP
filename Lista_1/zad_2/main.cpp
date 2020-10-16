#include <iostream>
#include <string>

template<typename T1, typename T2, typename OP>
auto add2(T1 a, T2 b, OP op)
{
    return op(a, b);
}

int main()
{
    constexpr auto add = [](auto a, auto b){return a + b;};
    constexpr auto str_add = [](std::string &a, std::string &b){return a + " " + b;};

    std::cout << add2(5 ,3, add) << "\n";
    std::cout << add2(5.5 ,3, add) << "\n";

    std::string str_part_1 = "Hello";
    std::string str_part_2 = "World";
    std::cout << add2(str_part_1 ,str_part_2, str_add) << "\n";

    return 0;
}
