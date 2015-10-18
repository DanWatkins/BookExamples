#ifndef c02e06_h
#define c02e06_h

#include <stdint.h>
#include <mutex>

class AtomicCounter
{
public:
	AtomicCounter& operator ++()
	{
		std::lock_guard<std::mutex> lk(_mutex);
		++_counter;

		return *this;
	}


	uint64_t value() const
	{
		return _counter;
	}

private:
	uint64_t _counter = 0;
	std::mutex _mutex;
};

#endif
