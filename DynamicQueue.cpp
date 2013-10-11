/*

 * Stack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 */

#ifndef _DYNAMIC_QUEUE_CPP_
#define _DYNAMIC_QUEUE_CPP_

#include "DynamicQueue.h"
#include <cstdlib>
#include <iostream>

template<class T>
DynamicQueue<T>::DynamicQueue() {
	head = 0;
	tail = 0;
}

template<class T>
DynamicQueue<T>::~DynamicQueue() {
	if (head) {
		this->clear();
	}
}

template<class T>
void DynamicQueue<T>::add(T data) {
	Element * tmp = new Element;
	tmp->data = data;
	tmp->next = 0;

	if (!head) {
		head = tmp;
		tail = tmp;
	} else if (!head->next) {
		tail = tmp;
		head->next = tail;
	} else {
		tail->next = tmp;
		tail = tmp;
	}
}

template<class T>
T DynamicQueue<T>::next() {
	if (head) {
		Element tmp = *head;

		delete head;
		if (!(head = tmp.next)) {
			tail = NULL;
		}

		return tmp.data;
	}

	return NULL;
}

template<class T>
T DynamicQueue<T>::firstElem() {
	if (head) {
		return head->data;
	}
	return NULL;
}

template<class T>
bool DynamicQueue<T>::isEmpty() {
	bool out = head ? 0 : 1;
	return out;
}

template<class T>
void DynamicQueue<T>::clear() {
	Element * tmp = head;

	while (tmp) {
		head = head->next;
		delete tmp;
		tmp = head;
	}
}

template<class T>
int DynamicQueue<T>::count() {
	Element * tmp = head;
	int counter = 0;

	while (tmp) {
		counter++;
		tmp = tmp->next;
	}

	return counter;
}

template<class T>
void DynamicQueue<T>::print(const char * msg) {
	Element * tmp = head;

	std::cout << "*** " << msg << " ***" << std::endl;
	std::cout << "DynamicQueue: ";

	while (tmp) {
		std::cout << tmp->data;
		tmp = tmp->next;
	}

	std::cout << std::endl;
	std::cout << "firstElem: " << this->firstElem() << std::endl;
	std::cout << "isEmpty: " << this->isEmpty() << std::endl;
	std::cout << "counter: " << this->count() << std::endl;
	std::cout << std::endl << std::endl;
}

#endif
