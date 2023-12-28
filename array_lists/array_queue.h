#pragma once

#include <algorithm>
#include <array_lists/array.h>
#include <random>

namespace ods {

template <typename T> class ArrayQueue {
public:
  ArrayQueue(int n) : arr_(n) {}
  ~ArrayQueue() {}

  void resize() {
    Array<T> b(std::max(1, 2 * n_));
    for (int k = 0; k < n_; k++) {
      b[k] = arr_[(j_ + k) % arr_.length_];
    }
    arr_ = b;
    j_ = 0;
  }

  T front() { return arr_[j_]; }

  T back() {
    assert(n_ > 0);
    return arr_[(j_ + n_ - 1) % arr_.length_];
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
  int j_ = 0;
  // actually number of elements
  int n_ = 0;
  Array<T> arr_;
};

template <typename T> class RandomQueue {
public:
  RandomQueue(int n) : arr_(n) {}
  ~RandomQueue() {}

  void resize() {
    Array<T> b(std::max(1, 2 * n_));
    for (int k = 0; k < n_; k++) {
      b[k] = arr_[k];
    }
    arr_ = b;
  }

  bool add(T x) {
    if (n_ + 1 > arr_.length_) {
      resize();
    }
    arr_[n_] = x;
    n_++;
    return true;
  }

  T remove() {
    assert(n_ > 0);
    int rand = std::rand() % n_;
    T x = arr_[rand];
    arr_[rand] = arr_[n_ - 1];
    n_--;
    if (arr_.length_ >= 3 * n_) {
      resize();
    }
    return x;
  }

  int size() { return n_; }

protected:
  // actually number of elements
  int n_ = 0;
  Array<T> arr_;
};

} // namespace ods