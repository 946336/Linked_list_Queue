#ifndef QUEUE_CPP
#define QUEUE_CPP

#include <iostream>
using namespace std;
#include "queue.h"
#include "dLinkedList.h"

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
template<typename T>
struct ListNode{
	ListNode(){
		prev = empty;
		next = empty;
	}
	// Don't think I need to do anything here
	~ListNode(){};

	// I'm horrified that I had to resort to this
	static constexpr node<T> empty = NULL;

	T data;
	node<T> next, prev;
};
#endif

// template <typename T>
// Queue<T>::~Queue(){
// 	break_circular();
// 	while(head->next != ListNode<T>::empty){
// 		head = deleteFirst(head);
// 	}
// }

// private; only used by destructor
template<typename T>
void Queue<T>::break_circular(){
	node<T> temp_node = head;
	while(next(temp_node) != head){
		temp_node = next(temp_node);
	}
	temp_node->next = ListNode<T>::empty;
}

template<typename T>
T Queue<T>::front(){
	return first(head);
}

template<typename T>
T Queue<T>::back(){
	return first(prev(head));
}

template<typename T>
void Queue<T>::enqueue(T newData){
	node<T> newNode = new ListNode<T>;
	newNode->data = newData;
	if(queueSize > 0){
		newNode->next = head;
		newNode->prev = prev(head);
		head->prev->next = newNode;
		head->prev = newNode;
	}
	else {
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
	}
	queueSize++;
}

template<typename T>
T Queue<T>::dequeue(){
	cout << "Oi" << endl;
	node<T> toDelete = head;
	cout << "MM" << endl;
	T data = first(toDelete);
	cout << "WW" << endl;
	toDelete->prev->next = next(toDelete);
	toDelete->next->prev = prev(toDelete);
	if(queueSize >= 1) head = next(toDelete);
	else head = ListNode<T>::empty;
	cout << "Yo" << endl;
	delete toDelete;
	queueSize--;
	return data;
}

template<typename T>
int Queue<T>::size(){
	return queueSize;
}


#endif

// force instantiation for std:: types
// template class Queue<char>;
// template class Queue<char16_t>;
// template class Queue<char32_t>;
// template class Queue<wchar_t>;
// template class Queue<signed char>;
// template class Queue<signed short int>;
// template class Queue<signed int>;
// template class Queue<signed long int>;
// template class Queue<signed long long int>;
// template class Queue<unsigned char>;
// template class Queue<unsigned short int>;
// template class Queue<unsigned int>;
// template class Queue<unsigned long int>;
// template class Queue<unsigned long long int>;
// template class Queue<float>;
// template class Queue<double>;
// template class Queue<long double>;
// template class Queue<bool>;
