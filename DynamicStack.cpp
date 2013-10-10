/*

 * Stack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 */

#ifndef _STACK_CPP_
#define _STACK_CPP_

#include "DynamicStack.h"
#include <cstdlib>
#include <iostream>

template<class T>
DynamicStack<T>::DynamicStack() {
	top = 0;
}

template<class T>
DynamicStack<T>::~DynamicStack() {
	if(top) {
		this->clear();
	}
}

template<class T>
void DynamicStack<T>::push(T data) {
	Element * tmp = new Element;

	tmp->data = data;
	tmp->next = top;

	top = tmp;
}

template<class T>
T DynamicStack<T>::pop() {
	if (top) {
		Element tmp = *top;
		delete top;

		if (tmp.next) {
			top = tmp.next;
		} else {
			top = 0;
		}

		return tmp.data;
	}

	return NULL;
}

template<class T>
T DynamicStack<T>::topElem() {
	if (top) {
		return top->data;
	}

	return NULL;
}

template<class T>
bool DynamicStack<T>::isEmpty() {
	bool out = top ? 0 : 1;
	return out;
}

template<class T>
void DynamicStack<T>::clear() {
	Element * tmp = top;

	while (tmp) {
		top = top->next;
		delete tmp;
		tmp = top;
	}
}

template<class T>
int DynamicStack<T>::count() {
	Element * tmp = top;
	int counter = 0;

	while (tmp) {
		counter++;
		tmp = tmp->next;
	}

	return counter;
}

template<class T>
void DynamicStack<T>::print(const char * msg) {
	Element * tmp = top;

	std::cout << "*** " << msg << " ***" << std::endl;
	std::cout << "Stack: ";

	while (tmp) {
		std::cout << tmp->data;
		tmp = tmp->next;
	}

	std::cout << std::endl;
	std::cout << "topElem: " << this->topElem() << std::endl;
	std::cout << "isEmpty: " << this->isEmpty() << std::endl;
	std::cout << "counter: " << this->count() << std::endl;
	std::cout << std::endl << std::endl;
}

#endif
