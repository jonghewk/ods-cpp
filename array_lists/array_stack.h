#pragma once

#include <algorithm>
#include <array_lists/array.h>

namespace ods {

template <typename T>
class ArrayStack {
public:
	ArrayStack(int n) : arr_(n) {
	}

	T get(int i) {
		return arr_[i];
	}

	T set(int i, T x) {
    T y = arr_[i];
    arr_[i] = x;
    return y;
	}
	
	void resize() {
		Array<T> b(max(1, 2 * n_));
    std::copy(arr_, arr_ + n_, b);
		arr_ = b;
  }


	void add(int i, T x) {
		if (n_ + 1 > arr_.length_) {
			resize();
		}
		std::copy_backward(arr_ + i, arr_ + n_, arr_ + n_ + 1);
		arr_[i] = x;
		n_++;
	}


	T remove(int i) {
		T x = arr_[i];
		for (int j = i; j < n_ - 1; j++) {
      arr_[j] = arr_[j + 1];
    }
		n_--;
		if (this->a_.length_ >= 3 * n_) {
			resize();
		}
	}

	int size() {
		return n_;
	}

protected:
	// actually number of elements
	int n_;
	Array<T> arr_;
};






} // namespace ods