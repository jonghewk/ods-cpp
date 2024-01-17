
#pragma once

namespace ods {

template <typename T> 
class Node {
public:
  Node(T x0) {
    x = x0;
    next = nullptr;
  }
  T x;
  Node *next = nullptr;
};

template <typename T> 
class SLList {
public:
  Node<T>* head;
	Node<T>* tail;
	
	int n; 
};
}

