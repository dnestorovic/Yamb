#ifndef THREADSAFEQUEUE_H
#define THREADSAFEQUEUE_H

#include <iostream>
#include <deque>
#include <mutex>
#include <iterator>
#include <cstring>
#include <string>

template <typename T>
class tsqueue_iterator;

template <typename T>
class tsqueue_const_iterator;

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
    T& front()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        return deqQueue.front();
    }

    // Only returns item from the back of deqQueue
    T& back()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        return deqQueue.back();
    }

    // Adds new item to front of deqQueue
    void push_front(const T& item)
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        deqQueue.emplace_front(std::move(item));
    }

    // Adds new item to back of deqQueue
    void push_back(const T& item)
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        deqQueue.emplace_back(std::move(item));
    }

    // Removes and returns item from the front of deqQueue
    T pop_front()
    {
        std::lock_guard<std::mutex> lock(muxQueue);

        auto front_item = std::move(deqQueue.front());
        deqQueue.pop_front();

        return front_item;
    }

    // Removes and returns item from the back of deqQueue
    T pop_back()
    {
        std::lock_guard<std::mutex> lock(muxQueue);

        auto back_item = std::move(deqQueue.back());
        deqQueue.pop_back();

        return back_item;
    }

    // Returns true if deqQueue has no items
    bool empty()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        return deqQueue.size() == 0;
    }

    // Returns number of items in deqQueue
    size_t count()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        return deqQueue.size();
    }

    // Erases all items in deqQueue
    void clear()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        deqQueue.clear();
    }

    // Returns size of deqQueue
    size_t size()
    {
        std::lock_guard<std::mutex> lock(muxQueue);
        return deqQueue.size();
    }

    // Index operator for deqQueue that return item on given position
    T &operator[](size_t index)
    {
        return deqQueue[index];
    }

    const T &operator[](size_t index) const
    {
        return deqQueue[index];
    }

    // Iterators for going through the deqQueue
    typedef tsqueue_iterator<T> iterator;
    typedef tsqueue_const_iterator<T> const_iterator;

    iterator begin()
    {
        return {*this, 0};
    }

    const_iterator cbegin() const
    {
        return {*this, 0};
    }

    const_iterator begin() const
    {
        return const_iterator(*this, 0);
    }

    iterator end()
    {
        return {*this, deqQueue.size()};
    }

    const_iterator end() const
    {
        return {*this, deqQueue.size()};
    }

    const_iterator cend() const
    {
        return {*this, deqQueue.size()};
    }

protected:
    std::mutex muxQueue;
    std::deque<T> deqQueue;
};

template <typename T>
class tsqueue_iterator
  : public std::iterator <std::bidirectional_iterator_tag, ThreadSafeQueue<T>> {
  friend class ThreadSafeQueue<T>;

public:

  // Dereference operator returns a reference to the item contained at the current position.
  T& operator* ()
  {
    return q_[pos_];
  }

  // Returns a const reference to the item contained at the current position
  const T& operator* () const
  {
    return q_[pos_];
  }

  // Pre-increment operator (++iter)
  tsqueue_iterator &operator++ ()
  {
      ++pos_;
      return *this;
  }

  // Post-increment operator (iter++)
  tsqueue_iterator operator++ (int)
  {
      return {q_, pos_++};
  }

  // Pre-decrement operator (--iter)
  tsqueue_iterator &operator-- ()
  {
      --pos_;
      return *this;
  }

  // Post-decrement operator (iter--)
  tsqueue_iterator operator-- (int)
  {
      return {q_, pos_--};
  }

  // Equality operator
  bool operator== (const tsqueue_iterator &rhs) const
  {
      return (&q_ == &rhs.q_) && (pos_ == rhs.pos_);
  }

  // Non-equality operator
  bool operator!= (const tsqueue_iterator &lhs) const
  {
      return !(*this == lhs);
  }

private:
  // Construct an tsqueue_iterator at position pos.
  tsqueue_iterator (ThreadSafeQueue<T> &q, size_t pos = 0)
    : q_(q), pos_(pos)
    {

    }

  // The ThreadSafeQueue we are dealing with
  ThreadSafeQueue<T> &q_;

  // Our current position
  mutable size_t pos_;
};

template <typename T>
class tsqueue_const_iterator
    : public std::iterator <std::bidirectional_iterator_tag, ThreadSafeQueue<T>> {
  friend class ThreadSafeQueue<T>;

public:
    // Returns a const reference to the item contained at the current position
    const T& operator* () const
    {
        return q_[pos_];
    }

    // Pre-increment operator
    tsqueue_const_iterator & operator++ ()
    {
        ++pos_;
        return *this;
    }

    // Post-increment operator
    tsqueue_const_iterator operator++ (int)
    {
        tsqueue_const_iterator old(*this);
        ++(*this);
        return old;
    }

    // Pre-decrement operator
    tsqueue_const_iterator &operator-- ()
    {
        --pos_;
        return *this;
    }

    // Post-decrement operator
    tsqueue_const_iterator operator-- (int)
    {
        return tsqueue_const_iterator( q_, pos_--);
    }

    // Equality operator
    bool operator== (const tsqueue_const_iterator &rhs) const
    {
        return (&q_ == &rhs.q_) && (pos_ == rhs.pos_);
    }

    // Non-equality operator
    bool operator!= (const tsqueue_const_iterator &lhs) const
    {
        return !(*this == lhs);
    }

private:
    // Construct an iterator at position pos.
    tsqueue_const_iterator (const ThreadSafeQueue<T> &q, size_t pos = 0)
        : q_(q)
        , pos_(pos)
    {}

    //The ThreadSafeQueue<T> we are dealing with
    const ThreadSafeQueue<T> &q_;

    // Our current position
    mutable size_t pos_;
};

#endif // THREADSAFEQUEUE_H
