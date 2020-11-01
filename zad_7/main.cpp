#include <iostream>

// PB: Mimo, że da się osiągnąć oczekiwany wynik stosując fold expressions,
//     to poprawne rozwiązanie powinno zawierać użycie ‘constexpr if’ oraz operatora ’sizeof…’.

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

