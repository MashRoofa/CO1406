#pragma once
#include <iostream>

using std::cout;

template <typename T>
struct Queue {
    T _data[MAX_SIZE];
    int _front = -1;
    int _back = -1;

    bool isEmpty() {
        return (_front == -1) || (_front > _back);
    }

    bool isFull() {
        return _back == (MAX_SIZE - 1);
    }

    void enqueue(T newVal) {
        if (isEmpty()) {
            _front = 0;
        }
        if (!isFull()) {
            _back++;
            _data[_back] = newVal;
        }
        else cout << "Queue is full\n\n";
    }

    T dequeue() {
        if (!isEmpty()) {
            T result = _data[_front++];
            return result;
        }
        else cout << "Queue is empty\n\n";
    }

    void rearrange() {
        if (_back == (MAX_SIZE - 1) && _front > 0) {
            for (int i = _front; i <= _back; i++)
                _data[i - _front] = _data[i];
            _back = _back - _front;
            _front = 0;
        }
    }

    void print() {
        if (!isEmpty()) {
            cout << "Queue\n";
            for (int i = _front; i <= _back; i++) {
                cout << _data[i] << "\t";
            }
            cout << "\n";
            cout << "front[" << _front << "]: " << _data[_front] << "\t";
            cout << "back[" << _back << "]: " << _data[_back] << "\n\n";
        }
        else cout << "Queue is empty\n\n";
    }

};
