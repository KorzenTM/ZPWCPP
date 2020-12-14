#ifndef LABORATORIUM_TASK_H
#define LABORATORIUM_TASK_H
#include <vector>
#include <thread>
#include <future>
#include <functional>
#include <cassert>
#include <mutex>
#include <iostream>
#include <atomic>

class Task
{
public:
    Task(int number_of_threads);
    void add_task(const std::function<double()> &task);
    double average();
    void stop();
    ~Task() = default;
private:
    void calculateSumOfTasks(int index);
    long unsigned int mNumberOfThreads;
    std::vector<std::thread> mThreads;
    std::vector<std::function<double()>> mTasks;
    double mSumOfResults = 0;
    std::mutex mtx;
    int counter = 0;
};


#endif //LABORATORIUM_TASK_H
