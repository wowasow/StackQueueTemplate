/*
 * Stack.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 */

#ifndef DYNAMIC_QUEUE_H_
#define DYNAMIC_QUEUE_H_

template<class T>
class DynamicQueue {
public:
	DynamicQueue();
	virtual ~DynamicQueue();

	// adds data at the end of the queue
	void add(T data);

	// pops data of the stack
	T next();

	// shows the top element
	T firstElem();

	// tells if the stack is empty
	bool isEmpty();

	// erases all stack elements
	void clear();

	// counts the elements(return a size variable)
	int count();

	// prints the stack elements
	void print(const char * msg);

private:
	struct Element {
		T data;
		Element * next;
	};

	Element * tail;
	Element * head;
};

#endif /* STACK_H_ */
