//
// Created by mateu on 16.01.2021.
//

#include "Silnik.h"

Silnik::Silnik(unsigned int interval, unsigned int fuelToDownload) : mInterval(interval), mFuelToDownload(fuelToDownload)
{
    mThread = std::thread{&Silnik::startEngine, this};
}

void Silnik::startEngine()
{
    std::unique_lock<std::mutex> lock(mtx);
    while(!mTanks.empty())
    {
        unsigned int currentFuel = mTanks.front()->pobierz(mFuelToDownload);

        if (currentFuel == 0)
        {
            mTanks.pop_front();
        }
        lock.unlock();

        std::this_thread::sleep_for(std::chrono::seconds(mInterval));

        lock.lock();
    }
}

void Silnik::connectTank(std::shared_ptr<ZbiornikPaliwa> &tank)
{
    std::cout << "Fuel tank added\n";
    std::unique_lock<std::mutex> uniqueLock(mtx);
    mTanks.push_back(tank);
}

Silnik::~Silnik()
{
    if (mThread.joinable())
        mThread.join();
}


