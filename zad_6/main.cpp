#include <iostream>


template<int a, int n>
struct hypercube_volume
{
    static constexpr int calculate()
    {
        if (a < 0 or n < 0) return -1;
        return a * hypercube_volume<a, n - 1>::calculate();
    }
};

template<int a>
struct hypercube_volume<a, 0>
{
    static constexpr int calculate()
    {
        return 1;
    }
};


int main()
{
    static_assert(hypercube_volume<5, 5>::calculate() == 3125, "ERROR");
    std::cout << "V = " << hypercube_volume<-5, 4>::calculate() << "\n";
    std::cout << "V = " << hypercube_volume<5, 4>::calculate() << "\n";
    return 0;
}

