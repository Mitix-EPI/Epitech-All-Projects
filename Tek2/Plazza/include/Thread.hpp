/*
** EPITECH PROJECT, 2021
** B-CCP-400-MPL-4-1-theplazza-richard.habimana
** File description:
** thread
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <thread>

class Thread {
    public:
        Thread() noexcept = default;
        Thread(Thread &) = delete;
        Thread(const Thread &) = delete;
        Thread(const Thread &&) = delete;
        Thread(Thread &&other) noexcept;
        template <class Function, class Args>
        explicit Thread(Function&& f, Args&& args);
        ~Thread();


        template <class Function, class Args>
        void updateFunc(Function&& f, Args&& args);
        Thread &operator=(const Thread &) = delete;
        Thread &operator=(Thread && other) noexcept;

        void join(void);
        void detach(void);
        void swap(Thread &other);

        std::thread::id get_id(void) const;
        bool joinable(void) const;

    private:
        std::thread _t;
};

#endif /* !THREAD_HPP_ */
