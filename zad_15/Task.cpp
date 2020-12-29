#include "Task.h"

Task::Task(int number_of_threads):mNumberOfThreads(number_of_threads), mStop(false)
{
    std::lock_guard<std::mutex> guard(mtx);
    mCounter = 0;
    for(size_t i = 0; i < mNumberOfThreads; i++)
    {
        mThreads.emplace_back(&Task::runThreads, this);
    }
}

void Task::add_task(const std::function<double()>& task)
{
    mTasks.push(task);
}

void Task::runThreads()
{
    std::unique_lock<std::mutex> lock(mtx);

    do
    {
        //wait until we have data
        mCV.wait(lock, [this] {
            return (!mTasks.empty() || mStop);
        });

        //after wait, we own the lock
        if (!mTasks.empty())
        {
            auto op = std::move(mTasks.front());
            mTasks.pop();

            //unlock now that we are done messing with the queue
            lock.unlock();
            mCounter++;
            mSumOfResults += op();

            lock.lock();
        }
    }while (!mStop);
}

double Task::average() const
{
    return mSumOfResults / mCounter;
}

void Task::stop()
{
    // Signal to dispatch threads that it's time to wrap up
    mStop = true;
    mCV.notify_all();

    // Wait for threads to finish their work before we exit
    for (auto & mThread : mThreads)
    {
        if (mThread.joinable())
        {
            mThread.join();
        }
    }
}









