#pragma once

#include "List.h"

template <typename T>
struct Stack {
	List<T> list;

	void push(T data) {
		list.insertFront(data);
	}

	void pop() {
		list.deleteFront();
	}

	T top() {
		return list.kth(1)->data;
	}
};
