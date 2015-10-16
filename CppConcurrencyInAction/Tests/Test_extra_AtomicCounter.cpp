//=============================================================================|
// Copyright (C) 2015 Valpineware
// This file is licensed under the MIT License.
//=============================================================================|

#include <ValpineBase/Test.h>
#include <extra_AtomicCounter.h>

#include <condition_variable>
#include <chrono>
#include <thread>
#include <list>
#include <iostream>

using namespace vbase;

class Test_extra_AtomicCounter : public test::Class
{
	Q_OBJECT

	std::condition_variable _cv;
	std::mutex _mutex;
	AtomicCounter _atomicCounter;
	const uint64_t _incrementTimes = 100000;

private slots:
	VTEST void t1()
	{
		std::list<std::thread> threads;

		{
			std::lock_guard<std::mutex> lk(_mutex);
			const unsigned threadCount = std::thread::hardware_concurrency()*4;

			for (unsigned i=0; i<threadCount; i++)
			{
				threads.push_back(std::thread([this]
				{
					{
						std::unique_lock<std::mutex> myLk(_mutex);
						_cv.wait(myLk, []{ return true; });
					}

					for (uint64_t i=0; i<_incrementTimes; i++)
						++_atomicCounter;
				}));
			}
		}

		_cv.notify_all();

		for (auto &t : threads)
			t.join();

		Verify_Eq(_atomicCounter.value(), _incrementTimes * threads.size());
	}
};

ADD_TESTCLASS(Test_extra_AtomicCounter)
#include "Test_extra_AtomicCounter.moc"
