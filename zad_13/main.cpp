#include <iostream>
#include <future>
#include <string>

thread_local std::thread::id id;
std::mutex mtx;

std::thread::id get_thread_id();
void print(const std::string &text);
void async_examples(std::launch policy);

int main()
{
    std::cout << "Thread ID = " << get_thread_id() << std::endl;
    std::string str_1 = "Hello Thread!";
    print(str_1);
    std::cout << "std::launch::async:\n";
    async_examples(std::launch::async);
    std::cout << "std::launch::deferred:\n";
    async_examples(std::launch::deferred);
    return 0;
}

std::thread::id get_thread_id()
{
    id = std::this_thread::get_id();
    return id;
}

void print(const std::string &text)
{
    std::lock_guard<std::mutex> guard(mtx);
    std::cout << get_thread_id() << " + " << text << std::endl;
}

void async_examples(std::launch policy)
{
    auto f_1 = std::async(policy, print, "First function");
    auto f_2 = std::async(policy, print, "Second function");
    auto f_3 = std::async(policy, print, "Third function");
}

