#include <iostream>
#include "Common/SinglyLinkedList.hpp"

typedef SinglyLinkedList::Node<int> Node;

/*
 * Returns the head node to a list which is the sum of input lists a and b.
 * Lists contain integers in reverse order. So the number 3762 should represented
 * in a list as 2, 6, 7, 3.
 */
Node* add(const Node *a, const Node *b)
{
	Node *sumList = new Node();
	Node *head = sumList;
	bool spill = false;
	const Node *ia = a;
	const Node *ib = b;
	
	while (ia || ib || spill)
	{
		//compute the total sum for this digit
		int sum =  0;
		if (ia && ia->data) sum += *ia->data;
		if (ib && ib->data) sum += *ib->data;
		if (spill) sum++;
		sumList->data = new int(sum%10);
		
		//decide if we overflowed the current digit
		spill = sum > 9;

		//allocate space for another sum?
		if ((ia ? ia->next : nullptr) || (ib ? ib->next : nullptr) || spill)
		{
			sumList->next = new Node;
			sumList = sumList->next;
		}
		
		//advance node pointers
		if (ia) ia = ia->next;
		if (ib) ib = ib->next;
	}
	
	return head;
}


int main()
{
	Node *a = new Node(new int(3));
	Node *aHead = a;
	a->next = new Node(new int(7)); a=a->next;
	a->next = new Node(new int(6)); a=a->next;
	a->next = new Node(new int(5)); a=a->next;
	a->next = new Node(new int(5)); a=a->next;
	
	Node *b = new Node(new int(4));
	Node *bHead = b;
	b->next = new Node(new int(4)); b=b->next;
	b->next = new Node(new int(4)); b=b->next;
	b->next = new Node(new int(3)); b=b->next;
	b->next = new Node(new int(6)); b=b->next;
	
	Node *sum = add(aHead, bHead);
	std::cout << "Sum is: ";
	
	while (sum != nullptr)
	{
		std::cout << *sum->data;
		
		if (sum->next)
			std::cout << ", ";
			
		sum = sum->next;
	}
}
