/*
 * QueueFromStack.cpp
 *
 *  Created on: Oct 9, 2013
 *      Author: wowas
 */

#include "QueueFromStack.h"

template<class T>
QueueFromStack<T>::QueueFromStack() {
	// TODO Auto-generated constructor stub

}

template<class T>
QueueFromStack<T>::~QueueFromStack() {
	this->clear();
}

template<class T>
void QueueFromStack<T>::add(T data) {
	tail.push(data);
}

template<class T>
T QueueFromStack<T>::next() {
	int size = tail.count();
	for (int i = 0; i < size; i++) {
		helper.push(tail.pop());
	}

	T data = helper.pop();

	for (int i = 0; i < size - 1; i++) {
		tail.push(helper.pop());
	}

	return data;
}

template<class T>
T QueueFromStack<T>::firstElem() {
	int size = tail.count();
	for (int i = 0; i < size; i++) {
		helper.push(tail.pop());
	}

	T data = helper.topElem();

	for (int i = 0; i < size; i++) {
		tail.push(helper.pop());
	}

	return data;
}

template<class T>
bool QueueFromStack<T>::isEmpty() {
	bool out = tail.count() ? false : true;
	return out;
}

template<class T>
void QueueFromStack<T>::clear() {
	tail.clear();
	helper.clear();
}

template<class T>
int QueueFromStack<T>::count() {
	return tail.count();
}

template<class T>
void QueueFromStack<T>::print(const char * msg) {
	std::cout << "*** QUEUE FROM STACK ***" << std::endl;
	std::cout << "*** " << msg << std::endl;
	std::cout << "TAIL STACK:" << std::endl;
	tail.print(msg);
	std::cout << "HELPER STACK:" << std::endl;
	helper.print(msg);

	std::cout << "firstElem: " << this->firstElem() << std::endl;
	std::cout << "isEmpty: " << this->isEmpty() << std::endl;
	std::cout << "count: " << this->count() << std::endl;
	std::cout << std::endl;

}
