/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** thread
*/

#include "Thread.hpp"

template <class Function, class Args>
Thread::Thread(Function&& f, Args&& args)
{
    this->_t(f, args);
}

Thread::Thread(Thread &&other) noexcept
{
    this->swap(other);
}

Thread &Thread::operator=(Thread && other) noexcept
{
    if (this->joinable())
        std::terminate();
    this->swap(other);
    return *this;
}

template <class Function, class Args>
void Thread::updateFunc(Function&& f, Args&& args)
{
    this->_t.~thread();
    this->_t(f, args);
}

Thread::~Thread()
{
    if (this->joinable())
        std::terminate();
}

void Thread::join(void)
{
    this->_t.join();
}

void Thread::detach(void)
{
    this->_t.detach();
}

void Thread::swap(Thread &other)
{
    this->_t.swap(other._t);
}

std::thread::id Thread::get_id(void) const
{
    return this->_t.get_id();
}

bool Thread::joinable(void) const
{
    return this->_t.joinable();
}
