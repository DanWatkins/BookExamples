#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

namespace SinglyLinkedList
{
	template<typename T>
	struct Node
	{
		T *data;
		Node<T> *next;
		
		Node() : data(nullptr), next(nullptr) {}
		Node(T *data) : data(data), next(nullptr) {}
		Node(T *data, Node<T> *next) : data(data), next(next) {}
		

		void deleteToEnd()
		{
			Node *iter = next;
			Node *iterToDelete = nullptr;
			
			while (iter != nullptr)
			{
				iterToDelete = iter;
				iter = iter->next;
				
				if (iterToDelete->data == nullptr)
					delete iterToDelete->data;
					
				delete iterToDelete;
			}
		}
	};
}

#endif

