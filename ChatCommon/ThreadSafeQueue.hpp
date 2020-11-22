#pragma once

#include "common.hpp"

template <typename T>
class ThreadSafeQueue
{
public:
	// TODO: support iterators

	void pop_front();

	void push_front(const T& item);

	void pop_back();

	void push_back(const T& item);

	T& front();

	T& back();

private:
	std::deque<T> data;
};