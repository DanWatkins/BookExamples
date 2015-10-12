// Created 2014.12.22 by Daniel L. Watkins
#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
struct Node
{
	Node *left = nullptr;
	Node *right = nullptr;
	T data;

	/**
	 * Returns a balanced binary tree with minimal heigt representing the sorted array.
	 */
	static Node* buildTreeFromSortedArray(std::vector<T> &sortedArray)
	{
		return subToNode(sortedArray, 0, sortedArray.size()-1);
	}

private:
	Node* subToNode(std::vector<T> &sortedArray, int low, int high)
	{
		if (high-low < 1)
			return nullptr;

		int distance = high-low+1;
		int centerPos = distance/2 + low;

		Node *node = new Node;
		node->data = sortedArray[centerPos];
		node->left = subToNode(sortedArray, low, centerPos-1);
		node->right = subToNode(sortedArray, centerPos+1, high);

		return node;
	}
};


#define ASSERT_TRUE(expression) if (!(expression)) \
								std::cout << "Problem at line " << __LINE__ << std::endl


int main()
{
	int data[] = { 1, 2, 3, 4, 5, 6, 7 };
	std::vector<int> sortedArray(data, data+7);

	Node<int>* node = Node<int>::buildTreeFromSortedArray(sortedArray);
}