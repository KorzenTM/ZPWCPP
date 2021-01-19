//
// Created by mateu on 16.01.2021.
//

#include <iostream>
#include "Silnik.h"
#include "ZbiornikPaliwa.h"

int main()
{
    Silnik silnik1(2, 5);
    Silnik silnik2(1, 1);
    Silnik silnik3(3, 2);

    std::list<std::shared_ptr<ZbiornikPaliwa>> tanks;

    for (int i = 0; i < 10 ; i++)
    {
        tanks.push_back(std::make_shared<ZbiornikPaliwa>(100));
    }

    for (auto &tank : tanks)
    {
        silnik1.connectTank(tank);
        silnik2.connectTank(tank);
        silnik3.connectTank(tank);
    }
    return 0;
}

