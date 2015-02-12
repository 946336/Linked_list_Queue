#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include <iostream>

template <class T> struct ListNode;
// template <class T>
// using node = ListNode<T>*;

template<class T>
bool isEmpty(ListNode<T>* lst);

template<class T>
ListNode<T>* prepend(T data, ListNode<T>* lst);

template<class T>
void postpend (T data, ListNode<T>* lst);

template<class T>
ListNode<T>* deleteFirst(ListNode<T>* lst);

template<class T>
void deleteLast(ListNode<T>* lst);

template<class T>
T first(ListNode<T>* lst);

template<class T>
ListNode<T>* next(ListNode<T>* lst);

template<class T>
ListNode<T>* prev(ListNode<T>* lst);

template<class T>
struct ListNode{
	ListNode(){
		prev = empty;
		next = empty;
		data = T();
	}
	// Don't think I need to do anything here
	~ListNode(){};

	// I'm horrified that I had to resort to this
	static ListNode<T>* empty;

	T data;
	ListNode<T> *next, *prev;
};

template <typename T>
ListNode<T>* ListNode<T>::empty = NULL;

template<class T>
bool isEmpty(ListNode<T>* lst){
	return lst == ListNode<T>::empty;
}

template<class T>
ListNode<T>* prepend(T data, ListNode<T>* lst){
	ListNode<T>* newNode(data);
	newNode->next = lst;
	if(lst != ListNode<T>::empty) lst->prev = newNode;
	return newNode;
}

// list must not be empty. Use prepend for empty lists!
template<class T>
void postpend (T newData, ListNode<T>* lst){
	ListNode<T>* newNode = new ListNode<T>;
	newNode->data = newData;
	ListNode<T>* tempNode = lst;
	while(tempNode != ListNode<T>::empty)
		tempNode = next(tempNode);
	tempNode->next = newNode;
	newNode->prev = tempNode;
} 

template<class T>
ListNode<T>* deleteFirst(ListNode<T>* lst){
	ListNode<T>* tempNode = lst;
	lst = next(lst);
	delete tempNode;
	lst->prev = ListNode<T>::empty;
	return lst;
}

template<class T>
void deleteLast(ListNode<T>* lst){
	ListNode<T>* temp = lst;
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

template<class T>
T first(ListNode<T>* lst){
	return lst->data;
}

template<class T>
ListNode<T>* next(ListNode<T>* lst){
	return lst->next;
}

template<class T>
ListNode<T>* prev(ListNode<T>* lst){
	return lst->prev;
}

# endif