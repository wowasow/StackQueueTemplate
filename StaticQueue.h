/*
 * StaticQueue.h
 *
 *  Created on: Oct 9, 2013
 *      Author: Wojciech Wrzalik
 *
 */

#ifndef STATIC_QUEUE_H_
#define STATIC_QUEUE_H_

template<class T>
class StaticQueue {
public:
	StaticQueue();
	StaticQueue(int size);
	virtual ~StaticQueue();

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
	T * queue;

	int tail;

	int size;

	const static int HEAD;
	const static int DEFAULT_SIZE;
};

#endif /* STATIC_QUEUE_H_ */
