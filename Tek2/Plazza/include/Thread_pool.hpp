/*
** EPITECH PROJECT, 2021
** Thread pool
** File description:
** Thread_pool
*/

#ifndef THREAD_POOL_HPP_
#define THREAD_POOL_HPP_

#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <thread>
#include "Thread.hpp"
#include "ConditionVariable.hpp"
#include "Cooks.hpp"

class Func_pool {
    public:
        Func_pool();
        ~Func_pool();
        void push(std::function<void(commandData_t *)> func, commandData_t *i);
        void shutdown();
        void infinite_loop();
        int getSizeQueue();

    protected:
    private:
        std::queue<std::pair<std::function<void(commandData_t *)>, commandData_t *>> _fqueue;
        std::condition_variable _condition_variable;
        std::atomic<bool> _accept_functions;
        std::mutex _mutex;
};

class Thread_pool {
    public:
        Thread_pool(int cook_nbr);
        ~Thread_pool();
        Func_pool _fpool;
        int _thread_nbr;
        std::vector<std::thread> _thread_pool;
};

#endif /* !THREAD_POOL_HPP_ */
