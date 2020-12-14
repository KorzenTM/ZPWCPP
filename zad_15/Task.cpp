#include "Task.h"

Task::Task(int number_of_threads):mNumberOfThreads(number_of_threads)
{
    std::lock_guard<std::mutex> guard(mtx);
    for(size_t i = 0; i < mNumberOfThreads; i++)
    {
        mThreads.emplace_back();
    }
}

void Task::add_task(const std::function<double()> &task)
{
    mTasks.push_back(task);

    if(mTasks.size() == mNumberOfThreads)
    {
        counter = mTasks.size();
        for(size_t i = 0; i < mNumberOfThreads; i++)
        {
            mThreads[i] = std::thread(&Task::calculateSumOfTasks, this, i);
            counter--;
            std::cout << "Task numer " << i << " has been completed" << "\n";
        }
    }
}

void Task::calculateSumOfTasks(int index)
{
    std::lock_guard<std::mutex> guard(mtx);
    mSumOfResults += mTasks[index]();
}

double Task::average()
{
    return mSumOfResults / mNumberOfThreads;
}

void Task::stop()
{
    if (counter == 0)
    {
        for(auto &thread :  mThreads)
        {
            thread.join();
        }
    }
}








