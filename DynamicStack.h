/*
 * Stack.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 */

#ifndef STACK_H_
#define STACK_H_

template<class T>
class DynamicStack {
public:
	DynamicStack();
	virtual ~DynamicStack();

	// pushes data on the stack
	void push(T data);

	// pops data of the stack
	T pop();

	// shows the top element
	T topElem();

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

	Element * top;
};

#endif /* STACK_H_ */
