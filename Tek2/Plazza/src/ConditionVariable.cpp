/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** ConditionVariable
*/

#include "ConditionVariable.hpp"

ConditionVariable::ConditionVariable()
{
}

ConditionVariable::~ConditionVariable()
{
}

void ConditionVariable::wait(std::unique_lock<std::mutex>& lck)
{
    this->_condition_variable.wait(lck);
}

template <class Predicate>
void ConditionVariable::wait(std::unique_lock<std::mutex>& lck, Predicate pred)
{
    this->_condition_variable.wait(lck, pred);
}

void ConditionVariable::notify_one() noexcept
{
    this->_condition_variable.notify_one();
}

void ConditionVariable::notify_all() noexcept
{
    this->_condition_variable.notify_all();
}
