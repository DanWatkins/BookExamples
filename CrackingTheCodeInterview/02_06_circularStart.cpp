#include <iostream>
#include <set>
#include "Common/SinglyLinkedList.hpp"

typedef SinglyLinkedList::Node<int> Node;

/*
 * Returns the Node at the start of a circularly linked list inside of the list.
 * If there is not a circular list inside, nullptr is returned.
 */
Node *findCircularStart(const Node *head)
{
	std::set<const Node*> previousNodes;
	const Node *iter = head;
	
	while (iter != nullptr)
	{
		previousNodes.insert(iter);
		
		if (previousNodes.find(iter->next) != previousNodes.end())
			return iter->next;
			
		iter = iter->next;
	}
	
	return nullptr;
}


int main()
{
	 Node *a = new Node(nullptr);
	 Node *b = new Node(nullptr);
	 Node *c = new Node(nullptr);
	 Node *d = new Node(nullptr);
	 Node *e = new Node(nullptr);
	 
	 a->next = b;
	 b->next = c;
	 c->next = d;
	 d->next = e;
	 e->next = c;
	 
	 std::cout << "a=" << a << ",b=" << b << ",c=" << c << ",d=" << d << ",e=" << e << std::endl;
	 std::cout << "circularStart=" << findCircularStart(a) << std::endl;
}
