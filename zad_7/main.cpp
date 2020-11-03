#include <iostream>

template<typename T, typename... Args>
constexpr auto adder(T first, Args... args)
{
    if constexpr (sizeof...(args) > 0)
    {
        return first + adder(args...);
    }
    else
    {
        return first;
    }
}

int main()
{
    auto sum1 = adder(6, 5, 5, 4.55);
    auto sum2 = adder(2);
    std::cout << sum1 << "\n";
    std::cout << sum2 << "\n";
    return 0;
}

