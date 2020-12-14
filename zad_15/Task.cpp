#include "Task.h"

Task::Task(int number_of_threads):mNumberOfThreads(number_of_threads)
{
    mTasks.reserve(mNumberOfThreads);
    std::lock_guard<std::mutex> guard(mtx);
    for(size_t i = 0; i < mNumberOfThreads; i++)
    {
        mThreads.emplace_back();
    }
}

void Task::add_task(std::function<double()> task)
{
    mTasks.push_back(task);
    if (mTasks.size() == mThreads.size())
    {
        counter = mTasks.size();
        runThreads();
    }
}

void Task::runThreads()
{
    for (size_t i = 0; i < mThreads.size(); i++)
    {
        mThreads[i] = std::thread(&Task::calculateSumOfTasks, this, i);
    }
}

void Task::calculateSumOfTasks(int index)
{
    std::lock_guard<std::mutex> guard(mtx);
    mSumOfResults += mTasks[index]();
    counter--;
}

double Task::average()
{
    return mSumOfResults / mNumberOfThreads;
}

void Task::stop()
{
    while(counter != 0)
    {
        std::cout << "Waiting for unfinished tasks...\n";
    }
    std::cout << "All of tasks have been done\n";
    for (auto &thread : mThreads)
        thread.join();
}









