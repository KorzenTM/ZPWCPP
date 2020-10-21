#include <iostream>

template<typename... Args>
constexpr auto adder(Args... args)
{
        return (args + ...);
}

int main()
{
    auto sum1 = adder(6, 5, 5, 4.55);
    std::cout << sum1 << "\n";

}

