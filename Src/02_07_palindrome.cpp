#include <iostream>
#include <stack>
#include "Common/SinglyLinkedList.hpp"

typedef SinglyLinkedList::Node<int> Node;
typedef SinglyLinkedList::List<int> List;

bool isPalindrome(const Node *head)
{
	const Node *fast = head;
	const Node *slow = head;
	std::stack<int> firstHalf;
	
	while (fast != nullptr && fast->next != nullptr && slow != nullptr)
	{
		firstHalf.push(*slow->data);
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if (fast != nullptr && fast->next == nullptr)
		slow = slow->next;
		
	while (slow != nullptr)
	{
		if (firstHalf.top() != *slow->data)
			return false;
			
		firstHalf.pop();
		slow = slow->next;
	}
	
	return true;
}


int main()
{
	 List a;
	 a.append(1);
	 a.append(2);
	 a.append(1);
	 
	 std::cout << (isPalindrome(a.head()) ? "First test passed" : "First test failed") << std::endl;
	 
	 
	 List b;
	 b.append(4);
	 b.append(5);
	 b.append(6);
	 b.append(7);
	 
	 std::cout << (!isPalindrome(b.head()) ? "Second test passed" : "Second test failed") << std::endl;
	 
	 List c;
	 c.append(46);
	 
	 std::cout << (isPalindrome(c.head()) ? "Third test passed" : "Third test failed") << std::endl;
}
