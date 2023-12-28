
#pragma once
#include <array_lists/array.h>


namespace ods {

template <typename T>
void rotate(const Array<T>& a, Array<T>& b, int r) {
	for (int i = 0; i < a.length_; i++) {
		b[(i + r) % b.length_] = a[i];
	}
}

inline int gcd(int n, int k) {
	if (k == 0) {
		return n;
	} else {
		return gcd(k, n % k);
	}
}

template <typename T>
void rotate_in_place(Array<T>& a, int r) {
	int d = -1;
	for (int i = 0; i < gcd(a.length_, r); i++) {
		int j = i;
		auto tmp = a[j];
		while (1) {
			d = j - r;
			if (d < 0) {
				d += a.length_;
			}
			if (d == i) {
				break;
			}
			a[j] = a[d];
			j = d;
		}
		a[j] = tmp;
	}
}

} // namespace ods