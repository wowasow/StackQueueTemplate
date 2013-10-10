#include "Stack.cpp"
#include "QueueFromStack.cpp"

void testStack();
void testQueueFromStack();

int main(int argc, char **argv) {

	testQueueFromStack();
//	testStack();

	return 0;
}

void testStack() {
	Stack<int> stack;

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
