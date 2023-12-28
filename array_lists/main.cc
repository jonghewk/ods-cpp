
#include "array_lists/array_deque.h"
#include <iostream>
#include <array_lists/array.h>
#include <array_lists/array_stack.h>
#include <array_lists/array_queue.h>
#include <array_lists/array_treque.h>
#include <array_lists/rotate.h>

void Exercise_2_1() {
	ods::ArrayStack<int> stack(2);
	stack.add(0, 1);		
	stack.add(0, 2);	
	stack.add(0, 3);
	stack.add(0, 4);		
	stack.add(0, 5);	
	stack.add(0, 6);

	std::cout << "[Before] add_all()" << "\n";
	for (int i = 0; i < stack.size(); i++) {
		std::cout << "i : " << stack.get(i) << "\n";
	}

	ods::Array<int> c(3);
	c[0] = 10;
	c[1] = 11;
	c[2] = 12;
	stack.add_all(2, c);

	std::cout << "[After] add_all()" << "\n";
	for (int i = 0; i < stack.size(); i++) {
		std::cout << "i : " << stack.get(i) << "\n";
	}
}

void Exercise_2_2() {
	std::cout << "[Test] Basic functionaliy " << "\n";
	{
		ods::ArrayQueue<int> queue(2);
		queue.add(1);
		queue.add(2);
		queue.add(3);
		std::cout << "remove : " << queue.remove() << "\n";
		queue.add(4);
		queue.add(5);
		queue.add(6);
		std::cout << "remove : " << queue.remove() << "\n";
		std::cout << "front : " << queue.front() << "\n";
		std::cout << "back : " << queue.back() << "\n";
	}
	std::cout << "[Test] random queue" << "\n";
	{
		ods::RandomQueue<int> rand_queue(4);
		rand_queue.add(1);
		rand_queue.add(2);
		rand_queue.add(3);
		rand_queue.add(4);
		rand_queue.add(5);

		std::cout << "remove : " << rand_queue.remove() << "\n";
		std::cout << "remove : " << rand_queue.remove() << "\n";
		std::cout << "remove : " << rand_queue.remove() << "\n";
		std::cout << "remove : " << rand_queue.remove() << "\n";
		std::cout << "remove : " << rand_queue.remove() << "\n";
	}
}

void Exercise_2_3() {
	ods::ArrayTreque<int> treque;
	treque.add(0, 1);
	treque.add(0, 2);
  treque.add(0, 3);
  treque.add(1, 4);
  treque.add(2, -1);

  for (int i = 0; i < treque.size(); i++) {
		std::cout << "i : " << treque.get(i) << "\n";
	}
}

void Exercise_2_4() {
	ods::Array<int> c(5);
	for (int i = 0; i < 5; i++) {
		c[i] = i + 1;
	}
	ods::Array<int> out(5);
	rotate(c, out, 3);
	for (int i = 0; i < 5; i++) {
		std::cout << "i : " << out[i] << "\n";
	}
	std::cout << "-------" << "\n";
	ods::rotate_in_place(c, 3);
	for (int i = 0; i < 5; i++) {
		std::cout << "i : " << c[i] << "\n";
	}
}

void Exercise_2_6() {
	ods::ArrayDeque<int> deque(1);
	deque.add(0, 1);
	deque.add(0, 2);
	deque.add(0, 3);
	deque.add(0, 4);

	for (int i = 0; i < deque.size(); i++) {
		std::cout << "i : " << deque.get(i) << "\n";
	}
}


int main() {
	// Exercise_2_1();
	// Exercise_2_2();
	// Exercise_2_3();
	// Exercise_2_4();
	Exercise_2_6();
	return 0;
}