#include <iostream>
#include <set>
#include "Common/SinglyLinkedList.hpp"

typedef SinglyLinkedList::Node<int> Node;

bool isPalindrome(const Node *node)
{
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
