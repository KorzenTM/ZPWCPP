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
    mSleep = true;
    while (true)
    {
        if (mSleep)
        {
            std::this_thread::sleep_for(std::chrono::seconds(mInterval));
        }

        std::lock_guard<std::mutex> guard(mtx);

        if (mTanks.empty())
        {
            std::cout << "The engine has been completed\n";
            return;
        }

        for(size_t i = 0; i < mTanks.size(); i++)
        {
            if (mTanks[i]->pobierz(mFuelToDownload) == 0)
            {
                std::cout << "The tank has been disconnected\n";
                mTanks.erase(mTanks.begin() + 1);
            }
            else
            {
                mSleep = false;
                break;
            }
        }

    }
}

void Silnik::connectTank(std::shared_ptr<ZbiornikPaliwa>& newTank)
{
    std::cout << "Fuel tank added\n";
    mTanks.push_back(newTank);
}

Silnik::~Silnik()
{
    if (mThread.joinable())
        mThread.join();
}


