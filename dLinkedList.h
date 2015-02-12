#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

template <typename T> struct listNode;
template <typename T>
using node = listNode<T>*;

template<typename T>
bool isEmpty(node<T> lst);

template<typename T>
node<T> prepend(T data, node<T> lst);

template<typename T>
void postpend (T data, node<T> lst);

template<typename T>
node<T> deleteFirst(node<T> lst);

template<typename T>
void deleteLast(node<T> lst);

template<typename T>
T first(node<T> lst);

template<typename T>
node<T> next(node<T> lst);

template<typename T>
node<T> prev(node<T> lst);

# endif