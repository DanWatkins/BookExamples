// Created 2015.02.08 by Daniel L. Watkins

#include <iostream>
#include <limits>

using namespace std;

template <typename T>
struct Node
{
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	T value;

	Node(T v) : value(v) {}

	static Node<T>* make(T value) { return new Node<T>(value); }

	bool isBst()
	{
		return check(this, std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
	}


private:
	bool check(const Node<T> *node, T min, T max)
	{
		if (!node)
			return true;

		if (node->value < min || node->value > max)
			return false;

		return check(node->left, min, node->value) || check(node->right, node->value, max);
	}
};


#define ASSERT_TRUE(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl

#define LEFT(parent, node, v) Node<int> node; parent.left = &node; node.value = v;
#define RIGHT(parent, node, v) Node<int> node; parent.right = &node; node.value = v;



typedef Node<int> node_i;
node_i* mk(int value, node_i *left=nullptr, node_i *right=nullptr)
{
	node_i *node = new node_i(value);
	node->left = left;
	node->right = right;

	return node;
}


int main()
{
	node_i *bal =	mk(7,
						mk(4,
							mk(2,
								mk(1),
								mk(3)),
							mk(5)),
						mk(11,
							mk(9,
								mk(8),
								mk(10)),
							mk(12)));
	ASSERT_TRUE(bal->isBst());


	node_i *un =	mk(4,
						mk(7,
							mk(3,
								mk(5)),
							mk(3)),
						mk(9,
							mk(1),
							mk(7)));
	ASSERT_TRUE(!un->isBst());
}