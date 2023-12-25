#pragma once

#include <algorithm>
#include <array_lists/array.h>

namespace ods {

template <typename T> class ArrayQueue {
public:
  ArrayQueue(int n) : arr_(n) {}

  void resize() {
    Array<T> b(max(1, 2 * n_));
    for (int k = 0; k < n_; k++) {
      b[k] = arr_[(j_ + k) % arr_.length_];
    }
    arr_ = b;
    j_ = 0;
  }


  bool add(T x) {
    if (n_ + 1 > arr_.length_) {
      resize();
    }
    arr_[(j_ + n_) % arr_.length_] = x;
    n_++;
    return true;
  }

  T remove() {
    T x = arr_[j_];
    j_ = (j_ + 1) % arr_.length_;
    n_--;
    if (arr_.length_ >= 3 * n_) {
      resize();
    }
    return x;
  }

  int size() { return n_; }

protected:
	int j_;
  // actually number of elements
  int n_;
  Array<T> arr_;
};

} // namespace ods