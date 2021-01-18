//
// Created by mateu on 16.01.2021.
//

#ifndef LABORATORIUM_SILNIK_H
#define LABORATORIUM_SILNIK_H

#include "ZbiornikPaliwa.h"
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>
#include <iostream>


class Silnik
{
private:
    std::vector<std::shared_ptr<ZbiornikPaliwa>> mTanks;
    unsigned int mInterval;
    unsigned int mFuelToDownload;
    std::mutex mtx;
    std::thread mThread;
    bool mSleep;

    void startEngine();
public:
    Silnik(unsigned int interval, unsigned fuelToDownload);
    void connectTank(std::shared_ptr<ZbiornikPaliwa>& newTank);
    ~Silnik();
};


#endif //LABORATORIUM_SILNIK_H
