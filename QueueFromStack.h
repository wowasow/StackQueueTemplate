/*
 * QueueFromStack.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 *
 */

#ifndef QUEUEFROMSTACK_H_
#define QUEUEFROMSTACK_H_

#include "DynamicStack.cpp"

template<class T>
class QueueFromStack {
public:
	QueueFromStack();
	virtual ~QueueFromStack();

	// adds data at the end of queue
	void add(T data);

	// gets the first element int queue
	T next();

	// shows the first element
	T firstElem();

	// tell if a queue is empty
	bool isEmpty();

	// erases all stack elements
	void clear();

	// counts elements(return a size variable)
	int count();

	// prints the stack elements
	void print(const char * msg);

private:
	DynamicStack<T> helper;
	DynamicStack<T> tail;
};

#endif /* QUEUEFROMSTACK_H_ */
