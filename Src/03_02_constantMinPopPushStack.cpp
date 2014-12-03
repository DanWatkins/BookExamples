#include <iostream>
#include <stack>


template<typename T>
class StackConstantPushPopMin_SpaceEfficient
{
public:
	/*
	 * Pushes the value onto the top of the stack in O(1)
	 */
	void push(T value)
	{
		if (mNodes.size() == 0  ||  mNodes.top().runningMin > value)
		{
			Node n;
			n.values.push(value);
			n.runningMin = value;
			mNodes.push(n);
		}
		else
		{
			mNodes.top().values.push(value);
		}
	}
	

	/*
	 * Pops the top element from the stack in O(1)
	 * @returns the element popped
	 */
	T pop()
	{
		std::stack<T> values = mNodes.top().values;
		T topValue = values.top();
		values.pop();
		
		if (values.size() == 0)
		{
			mNodes.pop();
		}
	}
	
	
	/*
	 * @returns the minimum element as ordered by the < operator in O(1)
	 */
	T min()
	{
		return mNodes.top().runningMin;
	}
	
	
private:
	struct Node
	{
		std::stack<T> values;
		T runningMin;
		
		Node() : runningMin(0) {} //wont work for things other than numbers, but that doesn't matter right now
	};

	std::stack<Node> mNodes;
};


#define myAssert(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl;

int main()
{
	StackConstantPushPopMin_SpaceEfficient<int> s;
	
	s.push(3);
	myAssert(s.min() == 3)
	s.push(2);
	myAssert(s.min() == 2)
	s.push(1);
	myAssert(s.min() == 1)

	s.push(5);
	myAssert(s.min() == 1)
	s.push(0);
	myAssert(s.min() == 0)
	
	return 0;
}
