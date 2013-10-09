#include "Stack.cpp"

int main(int argc, char **argv) {
	Stack<int> stack;

	// testing push
	for (int i = 0; i < 10; i++) {
		stack.push(i);
		stack.print("push");
		if (i == 0 || i == 4 ) {
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

	return 0;
}
