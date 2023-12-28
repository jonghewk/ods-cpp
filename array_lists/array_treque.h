#pragma once
#include <array_lists/array_deque.h>

namespace ods {

template <typename T>
class ArrayTreque {
public:
  T get(int i) {
    if (i < left_.size()) {
      return left_.get(i);
    } else {
      return right_.get(i - left_.size());
    }
  }

  T set(int i, T x) {
    if (i < left_.size()) {
      return left_.set(i, x);
    } else {
      return left_.set(i - left_.size(), x);
    }
  }

  void balance() {
		if (left_.size() - right_.size() == 2) {
			auto tmp = left_.remove(left_.size() - 1);
			right_.add(0, tmp);
		}
		if (right_.size() - left_.size() == 2) {
			auto tmp = right_.remove(0);
			left_.add(left_.size(), tmp);
		}
  }

  void add(int i, T x) {
    if (i < left_.size()) {
      left_.add(i, x);
    } else {
      right_.add(i - left_.size(), x);
    }
    balance();
  }

  void remove(int i) {
    T x;
    if (i < left_.size()) {
      x = left_.remove(i);
    } else {
      x = left_.remove(i - left_.size());
    }
    balance();
    return x;
  }

  int size() { return left_.size() + right_.size(); }

  DualArrayDeque<T> left_;
  DualArrayDeque<T> right_;
};


} // namespace ods