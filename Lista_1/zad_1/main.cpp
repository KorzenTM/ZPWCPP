#include <iostream>
#include <string>

template<typename T1, typename T2>
auto add1(T1 &a, T2 &b)
{
    return a + b;
}

template<>
auto add1(std::string &a, std::string &b)
{
    return a + " " + b;
}

int main()
{
    int a = 5;
    int b = 10;
    std::cout << a << " + " << b << " = " << add1(a , b) << "\n";
    int c = 6;
    double d = 4.55;
    std::cout << c << " + " << d << " = " << add1(c , d) << "\n";
    std::string string_1("Hello");
    std::string string_2("World");
    std::cout << add1(string_1, string_2) << "\n";

    return 0;
}

