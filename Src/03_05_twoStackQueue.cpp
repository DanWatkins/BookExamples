// Created 2014.12.08 by Daniel L. Watkins
// This file is in the public domain

#include <stack>
#include <iostream>

template <typename T>
class TwoStackQueue
{
public:
	void push(T value)
	{
		mBuffer.push(value);
	}


	T& front()
	{
		flushIfNeeded();
		return mCurrent.top();
	}


	void pop()
	{
		flushIfNeeded();
		mCurrent.pop();
	}


private:
	std::stack<T> mCurrent, mBuffer;

	void flushIfNeeded()
	{
		if (!mCurrent.empty())
			return;

		while (!mBuffer.empty())
		{
			mCurrent.push(mBuffer.top());
			mBuffer.pop();
		}
	}
};


#define myAssert(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl

int main()
{
	TwoStackQueue<int> q;
	q.push(4);
	myAssert(q.front() == 4);
	q.push(5);
	myAssert(q.front() == 4);
	q.push(6);
	myAssert(q.front() == 4);

	q.pop();
	myAssert(q.front() == 5);

	q.push(7);
	myAssert(q.front() == 5);
	q.pop();
	myAssert(q.front() == 6);
}