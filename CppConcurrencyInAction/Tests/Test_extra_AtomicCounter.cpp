//=============================================================================|
// Copyright (C) 2015 Valpineware
// This file is licensed under the MIT License.
//=============================================================================|

#include <extra_AtomicCounter.h>

#include <condition_variable>
#include <chrono>
#include <thread>
#include <list>
#include <iostream>

#include <ValpineBase/Test.h>
#include <ValpineBase/Concurrent/Latch.h>

using namespace vbase;

class Test_extra_AtomicCounter : public test::Class
{
	Q_OBJECT

	AtomicCounter _atomicCounter;
	const uint64_t _incrementTimes = 1000;

private slots:
	VTEST void t1()
	{
		std::list<std::thread> threads;
		concurrent::Latch latch;

		//create all the threads we need
		{
			const unsigned threadCount = std::thread::hardware_concurrency()*5;

			for (unsigned i=0; i<threadCount; i++)
			{
				threads.push_back(std::thread([this, &latch]
				{
					latch.wait();

					for (uint64_t i=0; i<_incrementTimes; i++)
						++_atomicCounter;
				}));
			}
		}

		//TODO latch needs a way to wait for all threads to wait
		latch.unlock();

		for (auto &t : threads)
			t.join();

		VerifyEq(_atomicCounter.value(), _incrementTimes * threads.size());
	}
};

ADD_TESTCLASS(Test_extra_AtomicCounter)
#include "Test_extra_AtomicCounter.moc"
