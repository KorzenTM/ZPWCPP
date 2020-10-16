#ifndef LABORATORIUM_WEKTOR_H
#define LABORATORIUM_WEKTOR_H

#include <iostream>

template<typename T, size_t SIZE = 0>
class Wektor
{
private:
    T *_v_tab;
public:
    Wektor();
    ~Wektor();

    inline size_t size() const {return SIZE;}
    inline T & operator[](int n) {return _v_tab[n];}
    inline T operator[](int n) const {return _v_tab[n];}
};



#endif //LABORATORIUM_WEKTOR_H
