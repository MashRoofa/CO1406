#pragma once
#include "Stack.h"



template <typename T>
struct Queue2Stacks {
    Stack<T> in;
    Stack<T> out;

    bool isEmpty() {
        return (in.isEmpty() && out.isEmpty());
    }

    bool isFull() {
        return (in.isFull() && out.isFull());
    }

    void enqueue(T newVal) {
        in.push(newVal);
    }

    T dequeue() {
        if (!out.isEmpty()) {
            T result = out.top();
            out.pop();
            return result;
        }
        else if (!in.isEmpty()) {
            while (!in.isEmpty()) {
                out.push(in.top());
                in.pop();
            }
            T result = out.top();
            out.pop();
            return result;
        }
        else cout << "Queue is empty\n\n";
    }

};

