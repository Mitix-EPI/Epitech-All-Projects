/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** TsQueue
*/

#ifndef TSQUEUE_HPP_
#define TSQUEUE_HPP_

#include "commons/common.h"
#include "commons/ownedPackage.hpp"

template<typename T>
class TsQueue {
    public:
        TsQueue() = default;
        TsQueue(const TsQueue<T>&) = delete;
        virtual ~TsQueue() {clear();};
        const T &front()
        {
            std::scoped_lock lock(_muxQueue);
            return _deqQueue.front();
        }

        const T &back()
        {
            std::scoped_lock lock(_muxQueue);
            return _deqQueue.back();
        }

        void push_back(const T &item)
        {
            std::scoped_lock lock(_muxQueue);
            _deqQueue.emplace_back(std::move(item));
        }

        void push_front(const T &item)
        {
            std::scoped_lock lock(_muxQueue);
            _deqQueue.emplace_front(std::move(item));
        }

        bool empty()
        {
            std::scoped_lock lock(_muxQueue);
            return _deqQueue.empty();
        }

        std::size_t count(void)
        {
            std::scoped_lock lock(_muxQueue);
            return _deqQueue.size();
        }

        void clear(void)
        {
            std::scoped_lock lock(_muxQueue);
            _deqQueue.clear();
        }

        T pop_front(void)
        {
            std::scoped_lock lock(_muxQueue);
            auto item = std::move(_deqQueue.front());
            _deqQueue.pop_front();
            return item;
        }

        T pop_back(void)
        {
            std::scoped_lock lock(_muxQueue);
            auto item = std::move(_deqQueue.back());
            _deqQueue.pop_back();
            return item;
        }

        void wait(void)
        {
            while (empty())
            {
                std::unique_lock<std::mutex> ul(muxBlocking);
                cvBlocking.wait(ul);
            }
        }

    protected:
        std::mutex _muxQueue;
        std::deque<T> _deqQueue;
        std::condition_variable cvBlocking;
        std::mutex muxBlocking;
    private:
};

#endif /* !TSQUEUE_HPP_ */
