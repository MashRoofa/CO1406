#pragma once

#include "List.h"

template <typename T>
struct Queue {
	List<T> list;

	bool isEmpty() {
		return list.isEmpty();
	}

	void enqueue(T data) {
		list.insertBack(data);
	}

	T dequeue() {
		T result = list.kth(1)->data;
		list.deleteFront();
		return result;
	}
};