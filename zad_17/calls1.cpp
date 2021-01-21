//
// Created by mateu on 21.01.2021.
//
#include "calls1.h"

void calls1()
{
    auto &p = Singleton::instance();
    p.calls();
}