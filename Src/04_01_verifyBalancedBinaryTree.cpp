// Created 2014.12.21 by Daniel L. Watkins
#include <cstdlib>
#include <algorithm>
#include <iostream>

template <typename T>
struct Node
{
	Node *left = nullptr;
	Node *right = nullptr;
	T *data = new T;

	/**
	 * Returns true if this Node represents a balanced binary tree.
	 */
	bool isBalanced()
	{
		return Node<T>::depth(this) != -1;
	}

private:
	/**
	 * @returns the number of levels below and including /p node. If a the difference in depth
	 * between the left and right nodes is greater than 1, this function will return -1 indicating
	 * there is a balance issue underneath this node.
	 */
	static int depth(const Node<T> *node)
	{
		if (node == nullptr)
			return 1;

		int lDepth = depth(node->left);
		int rDepth = depth(node->right);

		if (lDepth == -1 || rDepth == -1 || abs(rDepth-lDepth) > 1)
			return -1;

		return std::max(lDepth, rDepth) + 1;
	}
};

#define ASSERT_TRUE(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl


void testBalanced()
{
	typedef Node<int> iNode;

	//build a tree
	iNode root, _1l, _2l, _2r, _1r;
	root.left = &_1l;
		_1l.left = &_2l;
		_1l.right = &_2r;
	root.right = &_1r;

	ASSERT_TRUE(root.isBalanced());
}


void testUnbalanced()
{
	typedef Node<int> iNode;

	//build a tree
	iNode root, _1l, _2l, _2r, _3l, _1r;
	root.left = &_1l;
		_1l.left = &_2l;
		_1l.right = &_2r;
			_2r.left = &_3l;
	root.right = &_1r;

	ASSERT_TRUE(!root.isBalanced());
}


int main()
{
	testBalanced();
	testUnbalanced();
}