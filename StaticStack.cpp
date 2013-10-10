/*

 * Stack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 */

#ifndef _STATIC_STACK_CPP_
#define _STATIC_STACK_CPP_

#include "StaticStack.h"

#include <cstdlib>
#include <iostream>
#include <cstdio>

template<class T>
StaticStack<T>::StaticStack() {
	stack = new T[10];
	size = 10;
	top = -1;
}

template<class T>
StaticStack<T>::StaticStack(int size) {
	this->size = size;
	if (this->size > 0) {
		stack = new T[size];
		top = -1;
	} else {
		fprintf(stderr, "ERROR! Size of a stack must be a positive number.\n");
	}
}

template<class T>
StaticStack<T>::~StaticStack() {
	if (size > 0) {
		delete stack;
		stack = 0;
		top = -1;
		size = 0;
	}
}

template<class T>
void StaticStack<T>::push(T data) {
	if (top < size) {
		stack[++top] = data;
	} else {
		fprintf(stderr, "ERROR! Stack is full, unable to push more data.\n");
	}
}

template<class T>
T StaticStack<T>::pop() {
	if (top >= 0) {
		return stack[top--];
	} else {
		fprintf(stderr, "ERROR! Stack is empty.\n");
	}
	return NULL;
}

template<class T>
T StaticStack<T>::topElem() {
	if (top >= 0) {
		return stack[top];
	}
	return NULL;
}

template<class T>
bool StaticStack<T>::isEmpty() {
	bool out = true;

	if(top >= 0) {
		out = false;
	}

	return out;
}

template<class T>
void StaticStack<T>::clear() {
	top = -1;
}

template<class T>
int StaticStack<T>::count() {
	return (top + 1);
}

template<class T>
void StaticStack<T>::print(const char * msg) {
	std::cout << "*** " << msg << " ***" << std::endl;
	std::cout << "StaticStack: ";

	for(int i = 0; i <= top; i++) {
		std::cout << stack[i];
	}

	std::cout << std::endl;
	std::cout << "topElem: " << this->topElem() << std::endl;
	std::cout << "isEmpty: " << this->isEmpty() << std::endl;
	std::cout << "counter: " << this->count() << std::endl;
	std::cout << std::endl << std::endl;
}

#endif
