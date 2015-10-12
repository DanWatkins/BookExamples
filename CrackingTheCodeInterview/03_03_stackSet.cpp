// Created 2014.12.03 by Daniel L. Watkins
// This file is in the public domain

#include <iostream>
#include <stack>
#include <memory>
#include <vector>

template <typename T>
class StackSet
{
public:
	StackSet()
	{
		mStacks.push_back(StackPtr(new Stack));
	}


	void push(T value)
	{
		if (mStacks.back()->size() >= MaxStackSize)
			mStacks.push_back(StackPtr(new Stack));

		mStacks.back()->push(value);
	}


	void pop()
	{
		mStacks.back()->pop();
		cleanTop();
	}


	T& top()
	{
		return mStacks.back()->top();
	}


private:
	typedef std::stack<T> Stack;
	typedef std::unique_ptr<Stack> StackPtr;
	std::vector<StackPtr> mStacks;

	static const int MaxStackSize = 2;

	void cleanTop()
	{
		if (mStacks.size() > 1 && mStacks.back()->size() == 0)
			mStacks.pop_back();
	}
};



#define myAssert(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl;

void test1()
{
	StackSet<int> s;

#define pushAssert(value) \
			s.push(value); \
			myAssert(s.top() == value)

	int values[10] = { 4, 3, 7, 6, 6, -1, 0, 8, 9, 4 };

	for (int i=0; i<10; i++)
	{
		pushAssert(values[i]);
	}
#undef pushAssert


#define popAssert(value) \
			s.pop(); \
			myAssert(s.top() == value)
	
	for (int i=8; i>0; i--)
	{
		printf("testing i=%i\n", i);
		popAssert(values[i]);
	}
#undef popAssert
}


void test2()
{
	StackSet<int> s;
	s.push(4);
	s.push(77);
	s.push(51);
	s.pop();

	myAssert(s.top() == 77)

	
}


int main()
{
	test1();
	test2();

	return 0;
}
