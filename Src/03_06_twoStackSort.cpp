// Created 2014.12.21 by Daniel L. Watkins
// This file is in the public domain

#include <stack>
#include <iostream>

using namespace std;

template <typename T>
void sortStack(stack<T> &s1)
{
	stack<T> s2;
	
	while (!s1.empty())
	{
		T temp = s1.top();
		s1.pop();
		
		while (!s2.empty() && s2.top() > temp)
		{
			s1.push(s2.top());

			s2.pop();
		}
		
		s2.push(temp);
	}
	
	s1.swap(s2);
}

#define myAssert(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl

int main()
{
	stack<int> s({ 6, 1, 5, 2, 4, 3 });
	sortStack<int>(s);
	
	myAssert(s.top() == 6);
	s.pop();
	myAssert(s.top() == 5);
	s.pop();
	myAssert(s.top() == 4);
}