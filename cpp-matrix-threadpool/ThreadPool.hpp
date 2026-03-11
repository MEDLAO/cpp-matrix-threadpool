//
//  ThreadPool.hpp
//  cpp-matrix-threadpool
//
//  Created by MEDLAO on 02/03/2026.
//

#ifndef ThreadPool_hpp
#define ThreadPool_hpp

#include <vector>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <functional>

class ThreadPool {
public:
    ThreadPool(size_t num_treads);
    ~ThreadPool();
    
    void enqueue(std::function<void()> task);
    
private:
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> tasks;
    std::mutex queue_mutex;
    std::condition_variable condition;
    bool stop;
};

#endif /* ThreadPool_hpp */
