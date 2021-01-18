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

    std::vector<ZbiornikPaliwa> tanks;

    for (size_t i = 0; i < 10; i++)
    {
        tanks.emplace_back(100);
        std::shared_ptr<ZbiornikPaliwa> sharedPtr = std::make_shared<ZbiornikPaliwa>(tanks[i]);
        silnik1.connectTank(sharedPtr);
        silnik2.connectTank(sharedPtr);
        silnik3.connectTank(sharedPtr);
    }
    return 0;
}

