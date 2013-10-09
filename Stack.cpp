/*
 * Stack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: wowas
 */

#include "Stack.h"
#include <cstdlib>
#include <iostream>

template<class T>
Stack<T>::Stack() {
	top = 0;
}

template<class T>
Stack<T>::~Stack() {
}

template<class T>
void Stack<T>::push(T data) {
	Element * tmp = new Element;

	tmp->data = data;
	tmp->next = top;

	top = tmp;
}

template<class T>
T Stack<T>::pop() {
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
T Stack<T>::topElem() {
	if (top) {
		return top->data;
	}

	return NULL;
}

template <class T>
bool Stack<T>::isEmpty() {
	bool out = top ? 0 : 1;
	return out;
}

template <class T>
void Stack<T>::clear() {
	Element * tmp = top;

	while(tmp) {
		top = top->next;
		delete tmp;
		tmp = top;
	}
}

template <class T>
int Stack<T>::count() {
	Element * tmp = top;
	int counter = 0;

	while(tmp) {
		counter++;
		tmp = tmp->next;
	}
}

template<class T>
void Stack<T>::print(const char * msg) {
	Element * tmp = top;

	std::cout << "*** " << msg << " ***"<< std::endl;
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
