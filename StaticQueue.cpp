/*
 * QueueFromStack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: wowas
 */

#include "StaticQueue.h"
#include <iostream>
#include <cstdio>

template<class T>
const int StaticQueue<T>::HEAD = 0;

template<class T>
const int StaticQueue<T>::DEFAULT_SIZE = 10;

template<class T>
StaticQueue<T>::StaticQueue() {
	queue = new T[DEFAULT_SIZE];
	tail = -1;
	size = DEFAULT_SIZE;
}

template<class T>
StaticQueue<T>::StaticQueue(int size) {
	if (size > 0) {
		queue = new T[size];
		tail = -1;
		this->size = size;
	}
}

template<class T>
StaticQueue<T>::~StaticQueue() {
	delete[] queue;
	queue = 0;
	tail = -1;
	size = 0;
}

template<class T>
void StaticQueue<T>::add(T data) {
	if (tail < size) {
		queue[++tail] = data;
	} else {
		fprintf(stderr, "ERROR! Stack is full, unable to add more data.\n");
	}
}

template<class T>
T StaticQueue<T>::next() {
	if (tail >= 0) {
		T data = queue[HEAD];
		for (int i = 1; i <= tail; i++) {
			queue[i - 1] = queue[i];
		}
		tail--;

		return data;
	}

	return NULL;
}

template<class T>
T StaticQueue<T>::firstElem() {
	if (tail >= 0) {
		return queue[HEAD];
	}

	return NULL;
}

template<class T>
bool StaticQueue<T>::isEmpty() {
	bool out = true;

	if (tail >= 0) {
		out = false;
	}

	return out;
}

template<class T>
void StaticQueue<T>::clear() {
	tail = -1;
}

template<class T>
int StaticQueue<T>::count() {
	return (tail + 1);
}

template<class T>
void StaticQueue<T>::print(const char * msg) {
	std::cout << "*** " << msg << " ***" << std::endl;
	std::cout << "StaticStack: ";

	for (int i = 0; i <= tail; i++) {
		std::cout << queue[i];
	}

	std::cout << std::endl;
	std::cout << "firstElem: " << this->firstElem() << std::endl;
	std::cout << "isEmpty: " << this->isEmpty() << std::endl;
	std::cout << "counter: " << this->count() << std::endl;
	std::cout << std::endl << std::endl;

}
