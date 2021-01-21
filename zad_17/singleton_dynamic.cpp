//
// Created by mateu on 21.01.2021.
//
#include "singleton_dynamic.h"

void calls2()
{
    auto &p = Singleton::instance();
    p.calls();
}

Singleton &instance()
{
    return Singleton::instance();
}