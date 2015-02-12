#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "dLinkedList.h"
#include <iostream>
using namespace std;

template <class T>
class Queue{
public:
	Queue(){
		queueSize = 0;
		head = ListNode<T>::empty;
	}
	~Queue(){
		break_circular();
		while(head->next != ListNode<T>::empty){
			head = deleteFirst(head);
		}
	}

	T front();
	T back();
	void enqueue(T newData);
	T dequeue();
	int size();
private:
	int queueSize;
	ListNode<T>* head;
	// reserved for destructor use
	void break_circular();
};

// private; only used by destructor
template<class T>
void Queue<T>::break_circular(){
	ListNode<T>* temp_node = head;
	while(next(temp_node) != head){
		temp_node = next(temp_node);
	}
	temp_node->next = ListNode<T>::empty;
}

template<class T>
T Queue<T>::front(){
	return first(head);
}

template<class T>
T Queue<T>::back(){
	return first(prev(head));
}

template<class T>
void Queue<T>::enqueue(T newData){
	ListNode<T>* newNode = new ListNode<T>;
	newNode->data = newData;
	if(queueSize > 0){
		newNode->next = head;
		newNode->prev = prev(head);
		head->prev->next = newNode;
		head->prev = newNode;
	}
	else if (queueSize == 0){
		newNode->next = newNode;
		newNode->prev = newNode;
		head = newNode;
	}
	queueSize++;
}

template<class T>
T Queue<T>::dequeue(){
	ListNode<T>* toDelete = head;
	T data = first(toDelete);
	toDelete->prev->next = next(toDelete);
	toDelete->next->prev = prev(toDelete);
	if(queueSize >= 1) head = next(toDelete);
	else head = ListNode<T>::empty;
	delete toDelete;
	queueSize--;
	return data;
}

template<class T>
int Queue<T>::size(){
	return queueSize;
}


#endif