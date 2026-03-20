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
                
                // Lock the queue mutex to safely access the shared task queue
                std::unique_lock<std::mutex> lock(queue_mutex);
                
                // Wait until a task is available in the queue or the thread pool is stopping
                condition.wait(lock, [this] { return stop || !tasks.empty(); });
                
                // Exit the worker thread if the pool is stopping and no tasks remain
                if (stop && tasks.empty())
                    return;
                
                // Retrieve the next task from the queue
                task = tasks.front();
                
                // Remove the task from the queue
                tasks.pop();
                
                // Release the mutex so other threads can access the task queue while this task executes
                lock.unlock();
                
                // Run the task
                task();
            }
        });
    }
}

void ThreadPool::enqueue(std::function<void()> task)
{
    // Lock the queue to safely add a task
    std::unique_lock<std::mutex> lock(queue_mutex);
    
    tasks.push(task);
    
    // Wake on worker thread to process the new task
    condition.notify_one();
}

ThreadPool::~ThreadPool()
{
    // lock the queue to safely update the stop flag
    std::unique_lock<std::mutex> lock(queue_mutex);
    
    stop = true; // signal all worker threads to stop processing
}
