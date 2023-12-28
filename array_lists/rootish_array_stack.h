#pragma once
#include <array_lists/array_stack.h>
namespace ods {

template <typename T> class RootishArrayStack {
public:
	int i2b(int i) {
		double db = (-3.0 + std::sqrt(9 + 8 * i)) / 2.0;
		int b = ceil(db);
		return b;
	}

	T get(int i) {
		int b = i2b(i);
		int j = i - b * ( b + 1) / 2.0;
		return blocks.get(b)[j];
	}

	ArrayStack<T*> blocks;
	int n;
};


} // namespace ods