#pragma once

#include <algorithm>
#include <array_lists/array.h>

namespace ods {

template <typename T> class ArrayStack {
public:
  ArrayStack() : arr_(1) {}

  ArrayStack(int n) : arr_(n) {}

  T get(int i) { return arr_[i]; }

  T set(int i, T x) {
    T y = arr_[i];
    arr_[i] = x;
    return y;
  }

  void resize() {
    Array<T> b(std::max(1, 2 * n_));
    std::copy(arr_.begin(), arr_.begin() + n_, b.begin());
    arr_ = b;
  }

  // Exercise 2.1
  void add_all(int i, const Array<T> &c) {
    if (n_ + c.length_ > arr_.length_) {
      // resize
      Array<T> b(std::max(1, 2 * (n_ + c.length_)));
      std::copy(arr_.begin(), arr_.begin() + n_, b.begin());
      arr_ = b;
    }
    std::copy_backward(arr_.begin() + i, arr_.begin() + n_,
                       arr_.begin() + n_ + c.length_);
    std::copy(&c[0], &c[0] + c.length_, arr_.begin() + i);
    n_ = n_ + c.length_;
  }

  void add(int i, T x) {
    if (n_ + 1 > arr_.length_) {
      resize();
    }
    std::copy_backward(arr_.begin() + i, arr_.begin() + n_,
                       arr_.begin() + n_ + 1);
    arr_[i] = x;
    n_++;
  }

  T remove(int i) {
    T x = arr_[i];
    for (int j = i; j < n_ - 1; j++) {
      arr_[j] = arr_[j + 1];
    }
    n_--;
    if (this->arr_.length_ >= 3 * this->n_) {
      resize();
    }
    return x;
  }

  int size() { return n_; }

  // actually number of elements
  int n_ = 0;
  Array<T> arr_;
};

} // namespace ods