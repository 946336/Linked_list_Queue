#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "dLinkedList.h"

template <typename T>
class Queue{
public:
	Queue(){
		queueSize = 0;
		head = ListNode<T>::empty;
	}
	~Queue();

	T front();
	T back();
	void enqueue(T newData);
	T dequeue();
	int size();
private:
	int queueSize;
	node<T> head;
	// reserved for destructor use
	void break_circular();
};

#endif