// lab05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

#define MAX_SIZE 10

/*
typedef struct Stack {
    int _data[MAX_SIZE];
    unsigned int _top = 0;
};

bool isEmpty(Stack &s) {
    return s._top == 0;
}

bool isFull(Stack& s) {
    return s._top == MAX_SIZE;
}

void push(Stack& s, int newVal) {
    if (!isFull(s)) {
        //s.data[s.top] = newVal;
        //s.top++;
        //OR more elegantly
        s._data[s._top++] = newVal;
    }
}

void pop(Stack& s) {
    if (!isEmpty(s)) {
        s._top--;
    }
}

int top(Stack& s) {
    if (!isEmpty(s)) {
        return s._data[s._top - 1];
    }
}

//helper function
void print(Stack& s) {
    if (!isEmpty(s)) {
        cout << "Printing stack from the top\n";
        for (int i = s._top - 1; i >= 0; i--) {
            cout << s._data[i] << "\n";
        }
        cout << "-----------\n\n";
    }
    else cout << "Stack is empty\n\n";
}
*/

/*
typedef struct Stack {
    int _data[MAX_SIZE];
    unsigned int _top = 0;

    bool isEmpty() {
        return _top == 0;
    }

    bool isFull() {
        return _top == MAX_SIZE;
    }

    void push(int newVal) {
        if (!isFull()) {
            _data[_top++] = newVal;
        }
    }

    void pop() {
        if (!isEmpty()) {
            _top--;
        }
    }

    int top() {
        if (!isEmpty()) {
            return _data[_top - 1];
        }
    }

    void print() {
        if (!isEmpty()) {
            cout << "Printing stack from the top\n";
            for (int i = _top - 1; i >= 0; i--) {
                cout << _data[i] << "\n";
            }
            cout << "-----------\n\n";
        }
        else cout << "Stack is empty\n\n";
    }

};
*/


template <typename T> 
struct Stack {
    T _data[MAX_SIZE];
    unsigned int _top = 0;

    bool isEmpty() {
        return _top == 0;
    }

    bool isFull() {
        return _top == MAX_SIZE;
    }

    void push(T newVal) {
        if (!isFull()) {
            _data[_top++] = newVal;
        }
    }

    void pop() {
        if (!isEmpty()) {
            _top--;
        }
    }

    T top() {
        if (!isEmpty()) {
            return _data[_top - 1];
        }
    }

    void print() {
        if (!isEmpty()) {
            cout << "Printing stack from the top\n";
            for (int i = _top - 1; i >= 0; i--) {
                cout << _data[i] << "\n";
            }
            cout << "-----------\n\n";
        }
        else cout << "Stack is empty\n\n";
    }

};

template <typename T>
struct Queue {
    T _data[MAX_SIZE];
    int _front = -1;
    int _back = -1;

    bool isEmpty() {
        return (_front==-1) || (_front > _back);
    }

    bool isFull() {
        return _back == (MAX_SIZE-1);
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


int main()
{
    /*
    Stack s1;
    print(s1);
    push(s1, 3);
    push(s1, 5);
    cout << "Top:" << top(s1) << endl;    
    push(s1, 2);
    cout << "Top:" << top(s1) << endl;
    print(s1);
    pop(s1);
    print(s1);
    push(s1, 1);
    cout << "Top:" << top(s1) << endl;
    print(s1);
    */

    /*
    Stack s1;
    s1.print();
    s1.push(3);
    s1.push(5);    
    s1.push(2);
    cout << "Top:" << s1.top() << endl;
    s1.print();
    s1.pop();
    s1.print();
    s1.push(1);
    cout << "Top:" << s1.top() << endl;
    s1.print();
    */
    
    /*
    Stack<int> s1;
    s1.print();
    s1.push(3);
    s1.push(5);
    s1.push(2);
    cout << "Top:" << s1.top() << endl;
    s1.print();
    s1.pop();
    s1.print();
    s1.push(1);
    cout << "Top:" << s1.top() << endl;
    s1.print();
    */

    /*
    Queue<int> q1;
    q1.print();
    cout << "enqueue: 1" << endl;
    q1.enqueue(1);
    q1.print();

    cout << "enqueue: 2" << endl;
    q1.enqueue(2);
    q1.print();

    cout << "enqueue: 3" << endl;
    q1.enqueue(3);
    q1.print();

    cout << "dequeue:" << q1.dequeue() << endl;
    q1.print();

    cout << "enqueue: 4" << endl;
    q1.enqueue(4);
    q1.print();

    cout << "dequeue:" << q1.dequeue() << endl;
    q1.print();

    cout << "dequeue:" << q1.dequeue() << endl;
    q1.print();

    cout << "dequeue:" << q1.dequeue() << endl;
    q1.print();

    cout << "dequeue:" << q1.dequeue() << endl;
    q1.print();
    */

    Queue<int> q2;
    for (int i = 1; i < 12; i++) {
        q2.enqueue(i);
        q2.print();
    }

    q2.dequeue();
    q2.print();
    q2.dequeue();
    q2.print();
    q2.dequeue();
    q2.print();


    q2.rearrange();
    q2.print();



}
