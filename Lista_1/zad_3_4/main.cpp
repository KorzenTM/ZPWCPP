#include "wektor.h"
#include "wektor.cpp"
#include <iostream>
#include <vector>

template<typename T1, typename T2>
double operator*(T1 &v1, T2 &v2);

template<typename T>
std::ostream &operator<<(std::ostream &F, std::vector<T> &v);


int main()
{
    const int SIZE = 2;
    Wektor<double, SIZE> v1;

    for (int i = 0; i < SIZE; i++)
        v1[i] = i + 0.6;

    std::cout << "v1 = " << v1 << "\n";

    std::vector<int> v2 = {4, 2};
    std::cout << "v2 = " << v2 << "\n";
    try
    {
        std::cout << "v1 * v2 = " << v1 * v2 << "\n";
    }
    catch (std::exception &E)
    {
        std::cout << E.what() << "\n";
    }

    try
    {
        std::cout << "v2 * v1 = " << v2 * v1 << "\n";
    }
    catch (std::exception &E)
    {
        std::cout << E.what() << "\n";
    }


}

template<typename T1, typename T2>
double operator*(T1 &v1, T2 &v2)
{
    if (v1.size() == 0 or v2.size() ==0 or v1.size() != v2.size())
    {
        throw std::invalid_argument("Vectors are not equal!");
    }
    size_t size = v1.size();
    double suma = 0;
    for (size_t i = 0; i < size; i++)
    {
        suma += v1[i] * v2[i];
    }
    return suma;
}

template<typename T>
std::ostream &operator<<(std::ostream &F, std::vector<T> &v)
{
    F << "(";
    std::cout << v[0];
    for (size_t i = 1; i < v.size(); ++i)
    {
        std::cout << ", " << v[i];
    }
    std::cout << ")";
    return F;
}


