/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** ConditionVariable
*/

#ifndef CONDITIONVARIABLE_HPP_
#define CONDITIONVARIABLE_HPP_

#include <condition_variable>
#include <mutex>

class ConditionVariable {
    public:
        ConditionVariable();
        ~ConditionVariable();

        template <class Predicate>
        void wait(std::unique_lock<std::mutex>& lck, Predicate pred);
        void wait(std::unique_lock<std::mutex>& lck);

        void notify_one() noexcept;
        void notify_all() noexcept;

    private:
        std::condition_variable _condition_variable;
};

#endif /* !CONDITIONVARIABLE_HPP_ */
