//
// Created by mateu on 21.01.2021.
//

#include "Singleton.h"

std::shared_ptr<Singleton> Singleton::theSingleInstance;
std::mutex Singleton::mMutex;

Singleton::Singleton()
{
    std::cout << this << "+\n";
    counter = 0;
}

Singleton &Singleton::instance()
{
    std::lock_guard<std::mutex> lock(mMutex);
    if (Singleton::theSingleInstance == nullptr)
        Singleton::theSingleInstance = std::make_shared<Singleton>(Singleton());
    return *Singleton::theSingleInstance;
}

void Singleton::calls()
{
    counter++;
    std::cout << "Object address ->" << Singleton::theSingleInstance.get() << "\n";
    std::cout << "Number of calls ->" << counter << "\n";

}

Singleton::~Singleton()
{
    std::cout << Singleton::theSingleInstance.get() << "-\n";
}

