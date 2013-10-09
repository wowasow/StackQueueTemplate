/*
 * Stack.h
 *
 *  Created on: Oct 9, 2013
 *      Author: wowas
 */

#ifndef STACK_H_
#define STACK_H_

template <class T>
class Stack {
public:
	Stack();
	virtual ~Stack();

	// push data on the stack
	void push(T data);

	// pop data of the stack
	T pop();

	// show the top element
	T topElem();

	// tell if the stack is empty
	bool isEmpty();

	// erase all stack elements
	void clear();

	// count the elements(return a size variable)
	int count();

	// prints the stack elements
	void print(const char * msg);


private:
	struct Element {
		T data;
		Element * next;
	};

	Element * top;
};

#endif /* STACK_H_ */
