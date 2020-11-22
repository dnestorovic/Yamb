#pragma once

#ifndef THREADSAFEQUEUE_HPP
#define THREADSAFEQUEUE_HPP

#include <iostream>
#include <deque>
#include <mutex>


template <typename T>
class ThreadSafeQueue
{

public:
    ThreadSafeQueue() = default;

    ThreadSafeQueue(const ThreadSafeQueue<T>&) = delete;
    
    virtual ~ThreadSafeQueue() 
    {
        clear();
    }

    // Only returns item from the front of deqQueue
    const T& front()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.front();
    }

    // Only returns item from the back of deqQueue
    const T& back()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.back();
    }

    // Adds new item to front of deqQueue
    void push_front(const T& new_item)
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.emplace_front(std::move(item));
    }
    
    // Adds new item to back of deqQueue
    void push_front(const T& new_item)
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.emplace_back(std::move(item));
    }

    // Removes and returns item from the front of deqQueue
    T pop_front()
    { 
        std::scoped_lock lock(muxQueue);

        auto front_item = std::move(deqQueue.front());
        deqQueue.pop_front();

        return front_item;
    }

    // Removes and returns item from the back of deqQueue
    T pop_back()
    { 
        std::scoped_lock lock(muxQueue);

        auto back_item = std::move(deqQueue.back());
        deqQueue.pop_back();

        return back_item;
    }

    // Returns true if deqQueue has no items
    bool empty()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.size();
    }

    // Returns number of items in deqQueue
    size_t count()
    {
        std::scoped_lock lock(muxQueue);
        return deqQueue.size();
    }


    // Erases all items in deqQueue
    void clear()
    {
        std::scoped_lock lock(muxQueue);
        deqQueue.clear();
    }


protected:
    std::mutex muxQueue;
    std::deque<T> deqQueue;

};


#endif