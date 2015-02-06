// Created 2015.02.06 by Daniel L. Watkins

#include <iostream>
#include <list>

using namespace std;

template <typename T>
struct Node
{
	Node<T> *left = nullptr;
	Node<T> *right = nullptr;
	T value;
};

template <typename T>
list<list<Node<T>*>> buildFrom(Node<T> *root)
{
	typedef Node<T>* node_t;

	list<list<node_t>> lists;
	list<node_t> parentList;
	parentList.push_back(root);

	while (parentList.size() > 0)
	{
		list<node_t> currentList;

		for (node_t &n : parentList)
		{
			if (n->left)
				currentList.push_back(n->left);
			if (n->right)
				currentList.push_back(n->right);
		}

		lists.push_back(parentList);
		parentList = currentList;
		currentList.clear();
	}

	return lists;
}




#define ASSERT_TRUE(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl


int main()
{
	#define LEFT(parent, node, v) Node<int> node; parent.left = &node; node.value = v;
	#define RIGHT(parent, node, v) Node<int> node; parent.right = &node; node.value = v;

	Node<int> root; root.value = 4;
		LEFT(root, l, 7)
				LEFT(l, ll, 3)
				RIGHT(l, lr, 3)
					LEFT(lr, lrl, 5)
		RIGHT(root, r, 9)
			LEFT(r, rl, 1)
			RIGHT(r, rr, 7)

	list<list<Node<int>*>> list = buildFrom<int>(&root);
}