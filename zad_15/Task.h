#ifndef LABORATORIUM_TASK_H
#define LABORATORIUM_TASK_H
#include <vector>
#include <thread>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <iostream>
#include <queue>
#include <atomic>

class Task
{
public:
    Task(int number_of_threads);
    void add_task(const std::function<double()>& task);
    double average() const;
    void stop();
    ~Task() = default;
private:
    void runThreads();

    std::vector<std::thread> mThreads;
    std::queue<std::function<double()>> mTasks;
    std::mutex mtx;
    std::condition_variable mCV;

    double mSumOfResults = 0;
    long unsigned int mNumberOfThreads;
    bool mStop;
    std::atomic<int> mCounter;
};


#endif //LABORATORIUM_TASK_H
