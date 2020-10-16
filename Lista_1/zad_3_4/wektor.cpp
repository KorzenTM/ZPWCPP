#include "wektor.h"

template<typename T, size_t SIZE>
Wektor<T, SIZE>::Wektor() : _v_tab(new T[SIZE])
{
    for (size_t i = 0; i < SIZE; i++)
        _v_tab[i] = T(0);
}

template<typename T, size_t SIZE>
Wektor<T, SIZE>::~Wektor()
{
    delete [] _v_tab;
}

template<typename T, size_t SIZE>
std::ostream &operator<<(std::ostream &F, Wektor<T, SIZE> &v)
{
    F << "(";
    std::cout << v[0];
    for (size_t i = 1; i < SIZE; ++i)
    {
        std::cout << ", " << v[i];
    }
    std::cout << ")";
    return F;
}





