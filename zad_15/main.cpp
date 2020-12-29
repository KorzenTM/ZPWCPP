#include "Task.h"
#include <iostream>

int main()
{
    Task tasks(10);
    std::function<double()> fun= []()
            {
                //std::cout << "Hello I am Task!\n";
                return 5.1 / 2;
            };

    for (int i = 0; i < 4; i ++)
    {
        tasks.add_task(fun);
    }
    tasks.stop();

    std::cout << "Average = " << tasks.average() << "\n";
}

