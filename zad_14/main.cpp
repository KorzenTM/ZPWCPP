#include <iostream>
#include <vector>
#include <thread>
#include <future>

const int N = 10;

void scalar_product(std::vector<double> const&v1, std::vector<double> const&v2, std::promise<double> &sum_promise);

int main()
{
    std::vector<double> v1 {1, 2};
    std::vector<double> v2 {3, -5};
    std::vector<std::thread> threads;
    std::vector<std::future<double>> futures;

    for (int i = 0; i < N; i++)
    {
        std::promise<double> scalar_promise;
        futures.push_back(std::future<double>(scalar_promise.get_future()));
        threads.emplace_back(&scalar_product, std::cref(v1), std::cref(v2), std::ref(scalar_promise));
        threads[i].join();
    }
    double sum = 0;
    for (auto &x : futures)
    {
        try
        {
            sum += x.get();
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << "\n";
        }
    }
    std::cout << "Total sum -> " << sum << "\n";
    return 0;
}

void scalar_product(std::vector<double> const&v1, std::vector<double> const&v2, std::promise<double> &sum_promise)
{
    try
    {
        if (v1.size() != v2.size())
        {
            throw std::invalid_argument("Invalid size!");
        }
        const int SIZE = v1.size();
        double sum = 0;
        for (int i = 0; i < SIZE; i++)
        {
            sum += v1[i] * v2[i];
        }
        sum_promise.set_value(sum); //notify future
    }
    catch (std::exception&)
    {
        sum_promise.set_exception(std::current_exception());
    }
}




