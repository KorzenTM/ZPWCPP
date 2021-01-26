//
// Created by mateu on 21.01.2021.
//

#ifndef LABORATORIUM_SINGLETON_H
#define LABORATORIUM_SINGLETON_H
#include <iostream>
#include <memory>
#include <mutex>


class Singleton
{
private:
    Singleton();
    static std::shared_ptr<Singleton> theSingleInstance;
    static std::mutex mMutex;
    int counter;
public:
    static Singleton &instance();
    void calls();
    ~Singleton();
};


#endif //LABORATORIUM_SINGLETON_H
