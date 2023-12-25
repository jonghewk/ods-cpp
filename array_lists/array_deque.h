#pragma once

#include <algorithm>
#include <array_lists/array.h>
#include <array_lists/array_stack.h>

namespace ods {
template <typename T> class DualArrayDeque {
public:

  T get(int i) {
		if (i < front_.size()) {
			return front_.get(front_.size() - i  - 1);
		} else {
			return back_.get(i - front_.size());
		 }
	}

	T set(int i, T x) {
		if (i < front_.size()) {
			return front_.set(front_.size() - i - 1, x);
		} else {
			return back_.set(i - front_.size(), x);
		}
	}

	void balance() {
		if (!(3 * front_.size() < back_.size() || 3 * back_.szie() < front_.size())) {
			return;
		}
		int n = front_.size() + back_.size();
		int nf = n / 2;
		
		Array<T> af(std::max(2 * nf, 1));
		for (int i = 0; i < nf; i++) {
			af[nf - i - 1] = get(i);
		}
		int nb = n - nf;
		Array<T> ab(std::max(2 * nb, 1));
		for (int i = 0; i < nb; i++) {
			ab[i] = get(nf + i);
		}
		front_.arr_ = af;
		front_.n_ = nf;
		back_.arr_ = ab;
		back_.n_ = nb;
	}

	void add(int i, T x) {
		if (i < front_.size()) {
			front_.add(front_.size() - i, x);
		} else {
			back_.add(i - front_.size(), x);
		}
		balance();
	}

	void remove(int i) {
		T x;
		if (i < front_.size()) {
			x = front_.remove(front_.size() - i - 1);
		} else {
			x = back_.remove(i - front_.size());
		}
		balance();
		return x;
	}

	int size() {
		return front_.size() + back_.size();
	}


protected:
	ArrayStack<T> back_;
	ArrayStack<T> front_;	
};

template <typename T> class ArrayDeque {
public:
  ArrayDeque(int n) : arr_(n) {}

  T get(int i) { return arr_[(j_ + i) % arr_.length_]; }

  T set(int i, T x) {
    T y = arr_[(j_ + i) % arr_.length_];
    arr_[(j_ + i) % arr_.length_] = x;
    return y;
  }

  void resize() {
    Array<T> b(max(1, 2 * n_));
    for (int k = 0; k < n_; k++) {
      b[k] = arr_[(j_ + k) % arr_.length_];
    }
    arr_ = b;
    j_ = 0;
  }

  void add(int i, T x) {
    if (n_ + 1 > arr_.length_) {
      resize();
    }

    if (i < n_ / 2) {
      j_ = (j_ == 0) ? (arr_.length_ - 1) : j_ - 1;
      for (int k = 0; k <= i - 1; k++) {
        arr_[(j_ + k) % arr_.length_] = arr_[(j_ + k + 1) % arr_.length_];
      }
    } else {
      for (int k = n_; k > i; k--) {
        arr_[(j_ + k) % arr_.length_] = arr_[(j_ + k - 1) % arr_.length_];
      }
      arr_[(j_ + i) % arr_.length_] = x;
    }
  }

  T remove(int i) {
    T x = arr_[(j_ + i) % arr_.length_];
    if (i < n_ / 2) {
      for (int k = i; k > 0; k--) {
        arr_[(j_ + k) % arr_.length_] = arr_[(j_ + k - 1) % arr_.length_];
      }
      j_ = (j_ + 1) % arr_.length_;
    } else {
      for (int k = i; k < n_ - 1; k++) {
        arr_[(j_ + k) % arr_.length_] = arr_[(j_ + k + 1) % arr_.length_];
      }
    }
    n_--;
    if (3 * n_ < arr_.length_) {
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