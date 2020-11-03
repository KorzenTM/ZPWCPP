#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
#include <string>

template<typename T1, typename T2>
auto add1(const T1 &a, const T2 &b) ->decltype(a+b)
{
    return a + b;
}

template<typename T1, typename T2>
auto add1(const T1 *a,const T2 *b)
{
    return *a + *b;
}

// PB: Lepiej zwracać std:string żeby uniknąć konieczności ręcznego zwalniania pamięci
template<>
auto add1(const char* a, const char *b)
{
    return std::string(a) + std::string(b);
}


// PB: Powinny być zdefiniowane osobne szablony do dodawania liczby przekazanych
//     przez referencje i przez wskaźniki
// PB: Zadanie nie jest rozwiązane poprawnie.

int main()
{
    int a = 5;
    int b = 10;
    int c = 6;
    double d = 4.55;

    int *p_a = &a;
    int *p_b = &b;
    int *p_c = &c;
    double *p_d = &d;

    std::cout << a << " + " << b << " = " << add1(a, b) << "\n";
    std::cout << a << " + " << b << " = " << add1(p_a , p_b) << "\n";
    std::cout << c << " + " << d << " = " << add1(p_c , p_d) << "\n";

    const char *s1 = "Hello ";
    const char *s2 = "World";

    std::cout << add1(s1, s2) << "\n";

    return 0;
}


