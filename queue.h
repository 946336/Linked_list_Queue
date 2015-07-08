#ifndef CIRCULAR_QUEUE_H
#define CIRCULAR_QUEUE_H

#include "dLinkedList.h"
using namespace std;

template <typename T>
class Queue{
public:
	Queue();
	Queue(const Queue<T> &source);

	~Queue();

	Queue<T>& operator= (const Queue<T> &source);

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

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
template<typename T>
struct ListNode{
	ListNode();
	// Don't think I need to do anything here
	~ListNode(){};

	// I'm horrified that I had to resort to this
	static constexpr node<T> empty = NULL;

	T data;
	node<T> next, prev;
};
#endif

// included b/c of current limitations of template classes
// appropriate include guards are in place
#include "queue.cpp"

#endif
