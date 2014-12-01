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
	
	
	typename<typename T>
	class List
	{
		public:
			List() : mSize(0), mHead(nullptr), mTail(nullptr) {}
			
			int size() { return mSize; }
			Node* head() { return mHead; }
			Node* tail() { return mTail; }
		
			void append(T value)
			{
				Node *node = new Node(new T(value));
				
				if (mSize == 0)
				{
					mHead = node;
					mTail = node;
				}
				else if (mSize == 1)
				{
					mHead->next = node;
					mTail = node;
				}
				else
				{
					mTail->next = node;
					mTail = node;
				}
				
				++mSize;
			}
		
		private:
			int mSize;
			Node<T> mHead, mTail;
	}
}

#endif

