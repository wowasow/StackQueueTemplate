#include <climits>

#include "DynamicStack.cpp"
#include "DynamicQueue.cpp"
#include "QueueFromStack.cpp"
#include "StaticStack.cpp"
#include "StaticQueue.cpp"

void testDynamicStack();
void testDynamicQueue();
void testQueueFromStack();
void testStaticStack();
void testStaticQueue();
void reverse();
void organize();
void swap();

template <class T>
void swapRecursive(DynamicStack<T> & from, DynamicStack<T> & to);

int main(int argc, char **argv) {

//	testQueueFromStack();
//	testDynamicStack();
//	testDynamicQueue();
//	testStaticStack();
//	testStaticQueue();
//	reverse();
//	organize();
	swap();

	return 0;
}

void testDynamicStack() {
	DynamicStack<int> stack;

	// testing push
	for (int i = 0; i < 10; i++) {
		stack.push(i);
		stack.print("push");
		if (i == 0 || i == 4) {
			// testing clear
			stack.clear();
			stack.print("clear");
		}
	}

	// testing pop
	for (int i = 0; i < 10; i++) {
		stack.pop();
		stack.print("pop");
	}
}

void testDynamicQueue() {
	DynamicQueue<int> queue;

	// testing push
	for (int i = 0; i < 10; i++) {
		queue.add(i);
		queue.print("push");
		if (i == 0 || i == 4) {
			// testing clear
			queue.clear();
			queue.print("clear");
		}
	}

	// testing pop
	for (int i = 0; i < 10; i++) {
		queue.next();
		queue.print("pop");
	}
}

void testQueueFromStack() {
	// testing Queue from Stack
	QueueFromStack<int> queue;

	for (int i = 0; i < 10; i++) {
		queue.add(i);
		queue.print("add");
		if (i == 0 || i == 4) {
			// testing clear
			queue.clear();
			queue.print("clear");
		}
	}

	// testing pop
	for (int i = 0; i < 10; i++) {
		queue.next();
		queue.print("next");
	}
}

void testStaticStack() {
	StaticStack<int> stack;

	// testing push
	for (int i = 0; i < 10; i++) {
		stack.push(i);
		stack.print("push");
		if (i == 0 || i == 4) {
			// testing clear
			stack.clear();
			stack.print("clear");
		}
	}

	// testing pop
	for (int i = 0; i < 10; i++) {
		stack.pop();
		stack.print("pop");
	}
}

void testStaticQueue() {
	// testing Static Queue
	StaticQueue<int> queue;

	for (int i = 0; i < 10; i++) {
		queue.add(i);
		queue.print("add");
		if (i == 0 || i == 4) {
			// testing clear
			queue.clear();
			queue.print("clear");
		}
	}

	// testing pop
	for (int i = 0; i < 10; i++) {
		queue.next();
		queue.print("next");
	}
}

/*
 * Zad 8 Odwróć porządek elementów na stosie korzystając z:
 * 			-jednego dodatkowego statu,
 * 			-jednej dodatkowej kolejki.
 */
void reverse() {
	DynamicStack<int> stack;
	DynamicStack<int> additionalStack;
	DynamicQueue<int> additionalQueue;

	const int SIZE = 10;

	for (int i = 0; i < SIZE; i++) {
		stack.push(i);
	}

	stack.print("Current ");

	// revert stack using an additional stack
	for (int i = 0; i < SIZE; i++) {
		additionalStack.push(stack.pop());
	}

	additionalStack.print("Reversed with a help of an additional stack");

	for (int i = 0; i < SIZE; i++) {
		additionalQueue.add(additionalStack.pop());
	}

	for (int i = 0; i < SIZE; i++) {
		stack.push(additionalQueue.next());
	}

	stack.print("Reversed with a help of an additional queue");
}

/*
 * Zad 9 Uporządkuj elementy na stosie według malejących wartości, korzystając z
 * jednego dodat-kowego stosu i kilku innych zmiennych lokalnych.
 *
 */
void organize() {
	int num[] = { 3, 4, 1, 5, 1, 5, 5, 9, 0, 19 };
	const int SIZE = sizeof(num) / sizeof(int);

	DynamicStack<int> stack;
	DynamicStack<int> additionalStack;

	for (int i = 0; i < SIZE; i++) {
		stack.push(i);
	}

	stack.print("Before");

	for (int i = 1; i < SIZE; i++) {
		int max = stack.pop();
		for (int j = SIZE - i; j > 0; j--) {
			int next = stack.pop();
			if (next > max) {
				additionalStack.push(max);
				max = next;
			} else {
				additionalStack.push(next);
			}
		}

		stack.push(max);

		int length = additionalStack.count();
		for (int k = 0; k < length; k++) {
			stack.push(additionalStack.pop());
		}
	}

	stack.print("After");
}

/*
 * Zad 10 Przenieś elementy ze stosu S1 na stos S2 tak, aby został zachowany porządek elementów
 *			- korzystając z jednego dodatkowego stosu,
 *			- nie korzystając z dodatkowego stosu, lecz wyłącznie z pewnej liczby zmiennych lokalnych
 *			  (rekurencyjnie).
 */
void swap() {
	DynamicStack<int> stackOne;
	DynamicStack<int> stackTwo;
	DynamicStack<int> helperStack;

	const int SIZE = 10;

	for (int i = 0; i < SIZE; i++) {
		stackOne.push(i);
	}

	stackOne.print("StackOne, before normal");
	stackTwo.print("StackTwo, before normal");

	for (int i = 0; i < SIZE; i++) {
		helperStack.push(stackOne.pop());
	}

	for (int i = 0; i < SIZE; i++) {
		stackTwo.push(helperStack.pop());
	}

	stackOne.print("StackOne, after normal, before recursive");
	stackTwo.print("StackTwo, after normal, before recursive");

	swapRecursive(stackTwo, stackOne);

	stackOne.print("StackOne, after recursive");
	stackTwo.print("StackTwo, after recursive");

}

template<class T>
void swapRecursive(DynamicStack<T> & from, DynamicStack<T> & to) {
	if (!from.isEmpty()) {
		T data = from.pop();
		swapRecursive(from, to);
		to.push(data);
	}
}
