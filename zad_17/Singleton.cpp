//
// Created by mateu on 21.01.2021.
//

#include "Singleton.h"

std::shared_ptr<Singleton> Singleton::theSingleInstance;

Singleton::Singleton()
{
    std::cout << this << "+\n";
    counter = 0;
}

Singleton &Singleton::instance()
{
    if (Singleton::theSingleInstance == nullptr)
        Singleton::theSingleInstance.reset(new Singleton);
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

