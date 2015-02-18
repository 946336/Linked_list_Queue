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

template<typename T>
Queue<T>::Queue(){
	queueSize = 0;
	head = ListNode<T>::empty;
}

template <typename T>
Queue<T>::~Queue(){
	break_circular();
	while(head->next != ListNode<T>::empty){
		head = deleteFirst(head);
	}
}

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
	node<T> toDelete = head;
	T data = first(toDelete);
	toDelete->prev->next = next(toDelete);
	toDelete->next->prev = prev(toDelete);
	if(queueSize >= 1) head = next(toDelete);
	else head = ListNode<T>::empty;
	delete toDelete;
	queueSize--;
	return data;
}

template<typename T>
int Queue<T>::size(){
	return queueSize;
}


#endif