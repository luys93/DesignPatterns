#include "ThreadPool.hpp"



int main()
{
    std::mutex mtx;
    int x = 5;
    int y = 3;


    ThreadPool t(2, 3);
    t.addToQueue([x , y, &mtx](){std::lock_guard<std::mutex> lock(mtx); std::cout << x + y << std::endl;});
    t.addToQueue([x, y, &mtx](){std::lock_guard<std::mutex> lock(mtx); std::cout << x * y << std::endl;});
    t.addToQueue([x, y, &mtx](){std::lock_guard<std::mutex> lock(mtx); std::cout << x + y * x << std::endl;});

}