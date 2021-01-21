//
// Created by mateu on 21.01.2021.
//

#include "calls1.h"
#include "singleton_dynamic.h"

int main()
{
    auto &p = Singleton::instance();
    p.calls();
    calls1();
    calls2();
    instance().calls();
}

