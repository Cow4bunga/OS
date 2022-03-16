#pragma once
#include <iostream>
#include <thread>
#include <mutex>
#include <queue>
#include <condition_variable>

template <class T>
class Channel {
public:
	
	Channel() : buffSize(100) {}

	Channel(int bSize) : buffSize(bSize) {}

	void send(T data)
	{
		std::unique_lock<std::mutex> uLock(qmutex);
		if (isClosed) {
			throw std::runtime_error("This channel is closed atm!");
		}

		c_var.wait(uLock, buff.size() != buffSize && !isClosed);
		buff.push(data);
		uLock.unlock();
		c_var.notify_one();
	}

	
	std::pair<T, bool> recv()
	{
		std::unique_lock<std::mutex> uLock(qmutex);
		c_var.wait(uLock, !buff.empty());
		T var = buff.front();
		buff.pop();
		uLock.unlock();
		c_var.notify_one();
		return std::make_pair<T, bool>(var, !isClosed);
	}

	
	void close()
	{
		std::unique_lock<std::mutex> uLock(qmutex);
		isClosed = true;
		uLock.unlock();
		c_var.notify_all();
	}


private:
	std::queue<T> buff;
	int buffSize;
	std::mutex qmutex;
	std::condition_variable c_var;
	bool isClosed=false;
};



