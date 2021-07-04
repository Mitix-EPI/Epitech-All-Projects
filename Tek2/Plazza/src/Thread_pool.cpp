/*
** EPITECH PROJECT, 2021
** Thread pool
** File description:
** Thread_pool
*/

#include "Thread_pool.hpp"

Thread_pool::Thread_pool(int cook_nbr)
:   _thread_nbr(cook_nbr)
{
    for (int i = 0; i < _thread_nbr; i++)
        _thread_pool.push_back(std::thread(&Func_pool::infinite_loop, &_fpool));
}

Thread_pool::~Thread_pool()
{
}

Func_pool::Func_pool()
:   _accept_functions(true)
{
}

Func_pool::~Func_pool()
{
}

void Func_pool::push(std::function<void(commandData_t *)> func, commandData_t *i)
{
    std::unique_lock<std::mutex> lock(_mutex);
    _fqueue.push(std::make_pair(func, i));
    lock.unlock();
    _condition_variable.notify_one();
}

void Func_pool::shutdown()
{
    std::unique_lock<std::mutex> lock(_mutex);
    _accept_functions = false;
    lock.unlock();
    _condition_variable.notify_all();
}

int Func_pool::getSizeQueue()
{
    return this->_fqueue.size();
}


void Func_pool::infinite_loop()
{
    std::function<void(commandData_t *)> func;
    commandData_t *com;

    while (true)
    {
        {
            std::unique_lock<std::mutex> lock(_mutex);
            _condition_variable.wait(lock, [this]() {return !_fqueue.empty() || !_accept_functions; });
            if (!_accept_functions && _fqueue.empty()) {
                return;
            }
            func = _fqueue.front().first;
            com = _fqueue.front().second;
            _fqueue.pop();
        }
        func(com);
    }
}