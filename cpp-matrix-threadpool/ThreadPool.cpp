//
//  ThreadPool.cpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 02/03/2026.
//

#include "ThreadPool.hpp"


ThreadPool::ThreadPool(size_t num_threads) : stop(false)
{
    for (size_t i = 0; i < num_threads; ++i)
    {
        // Create a worker thread and store it in the workers vector
        workers.emplace_back([this]() {
            while (true) {
                // Task retrieved from the task queue
                std::function<void()> task;
                
            }
        });
    }
}

void ThreadPool::enqueue(<#std::function<void ()> task#>)
{
    
}

ThreadPool::~ThreadPool()
{
    
}
