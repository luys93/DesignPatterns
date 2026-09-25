#pragma once

#include <iostream>
#include <mutex>
#include <functional>
#include <condition_variable>
#include <thread>
#include <queue>
#include <vector>

class SafeQueue
{
    private:
            std::mutex safe;
            std::condition_variable cvPush;
            std::condition_variable cvPop;
            size_t size_{0};
            std::queue<std::function<void()>> q_;
            bool isClosed{false};
    
    public:
            explicit SafeQueue(size_t size): size_{size}
            {

            }

            void push(std::function<void()> f)
            {
                std::unique_lock<std::mutex> lock(safe);
                cvPush.wait(lock, [this](){return q_.size() < size_ || isClosed == true;});
                if(isClosed == true)
                    return;
                q_.push(std::move(f));
                cvPop.notify_one();
            }


            bool pop(std::function<void()>& f)
            {
                std::unique_lock<std::mutex> lock(safe);
                cvPop.wait(lock, [this](){return !q_.empty() || isClosed == true;});
                if(!q_.empty())
                {
                    f = std::move(q_.front());
                    q_.pop();
                    cvPush.notify_one();
                    return true;
                }
                return false;
            };

            void close()
            {
                std::lock_guard<std::mutex> lock(safe);
                isClosed = true;
                cvPush.notify_all();
                cvPop.notify_all();
            }
};





class ThreadPool
{
    private:
            std::vector<std::thread> workers;
            SafeQueue q_;
    public:
            explicit ThreadPool(int numberOfThread,  size_t maxQueueSize) : q_{maxQueueSize}
            {
                for(int i = 0; i < numberOfThread; i++)
                {
                    workers.emplace_back(std::thread([this](){
                        while(true)
                        {
                            std::function<void()> f;
                            if(!q_.pop(f))
                                return;
                            f();
                        }
                    }));
                }
            }

            ~ThreadPool()
            {
                q_.close();
                for(auto& w : workers)
                {
                    if(w.joinable())
                        w.join();
                }
            }

            void addToQueue(std::function<void()> f)
            {
                q_.push(std::move(f));
            };
};