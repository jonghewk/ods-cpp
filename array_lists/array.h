#pragma once

#include <cassert>
#include <iostream>

namespace ods {
// Simple array
template <typename T> class Array {
public:
  typedef T *iterator;
  typedef const T *const_iterator;
  iterator begin() { return &a_[0]; }
  iterator end() { return &a_[length_]; }

  const_iterator cbegin() { return &a_[0]; }
  const_iterator cend() { return &a_[length_]; }

  explicit Array(int len) : length_(len), a_(new T[len]) {}
  ~Array() {
    if (a_ != nullptr) {
      delete[] a_;
    }
  }

  Array(const Array &b) {
    if (a_ != nullptr) {
      delete[] a_;
    }
    a_ = new T[b.length_];
    length_ = b.length_;
    std::memcpy(a_, b.a_, b.length_ * sizeof(T));
  }

  Array(Array &&b) {
    if (a_ != nullptr) {
      delete[] a_;
    }
    a_ = b.a_;
    length_ = b.length_;
    b.a_ = nullptr;
  }

  Array<T> &operator=(const Array<T> &b) {
    if (this == &b)
      return *this;

    if (a_ != nullptr) {
      delete[] a_;
    }
    a_ = new T[b.length_];
    length_ = b.length_;
    std::memcpy(a_, b.a_, b.length_ * sizeof(T));
    return *this;
  }

  Array<T> &operator=(Array<T> &&b) {
    if (this == &b)
      return *this;

    if (a_ != nullptr) {
      delete[] a_;
    }
    a_ = b.a_;
    length_ = b.length_;
    b.a_ = nullptr;
  }

  T &operator[](int i) const {
    assert(i >= 0 && i < length_);
    return a_[i];
  }

  T *a_;
  int length_;
};

} // namespace ods
