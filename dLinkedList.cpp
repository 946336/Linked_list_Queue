#ifndef DLINKEDLIST_CPP
#define DLINKEDLIST_CPP

#include <iostream>
using namespace std;
#include "dLinkedList.h"

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

template<typename T>
ListNode<T>::ListNode(){
	prev = empty;
	next = empty;
	data = T();
}

template<typename T>
bool isEmpty(node<T> lst){
	return lst == ListNode<T>::empty;
}

template<typename T>
node<T> prepend(T data, node<T> lst){
	node<T> newNode(data);
	newNode->next = lst;
	if(lst != ListNode<T>::empty) lst->prev = newNode;
	return newNode;
}

// list must not be empty. Use prepend for empty lists!
template<typename T>
void postpend (T newData, node<T> lst){
	node<T> newNode = new ListNode<T>;
	newNode->data = newData;
	node<T> tempNode = lst;
	while(tempNode != ListNode<T>::empty)
		tempNode = next(tempNode);
	tempNode->next = newNode;
	newNode->prev = tempNode;
} 

template<typename T>
node<T> deleteFirst(node<T> lst){
	node<T> tempNode = lst;
	lst = next(lst);
	delete tempNode;
	lst->prev = ListNode<T>::empty;
	return lst;
}

template<typename T>
void deleteLast(node<T> lst){
	node<T> temp = lst;
	if(lst->next == ListNode<T>::empty){
		delete lst;
		return ListNode<T>::empty;
	}
	while(temp->next != ListNode<T>::empty){
		temp = next(temp);
	}
	temp->prev->next = ListNode<T>::empty;
	delete temp;
	return lst;
}

template<typename T>
T first(node<T> lst){
	return lst->data;
}

template<typename T>
node<T> next(node<T> lst){
	return lst->next;
}

template<typename T>
node<T> prev(node<T> lst){
	return lst->prev;
}

#endif