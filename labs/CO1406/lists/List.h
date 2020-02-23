#pragma once

#include <iostream>

using std::cout;

template <typename T>
struct Node {
    T data;
    Node* next;
};

template <typename T>
struct List {
    unsigned int size = 0;
    Node<T>* head = nullptr;

    bool isEmpty() {
        return size == 0;
    }

    Node<T>* createNode(T newData) {
        Node<T>* newNode = new Node<T>();
        newNode->data = newData;
        newNode->next = nullptr;
        return newNode;
    }

    Node<T>* find(T data) {
        for (Node<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->data == data) return tmp;
        }
        return nullptr;
    }

    bool exists(T data) {
        /*
        for (Node<T>* tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (tmp->data == data) return true;
        }
        return false;
        */
        return find(data) != nullptr;
    }

    Node<T>* access(unsigned int k) {
        if (size >= k) {
            Node<T>* tmp = head; 
            for (int i = 1; tmp != nullptr && i < k; tmp = tmp->next, i++);
            return tmp;            
        }
        else return nullptr;
    }

    void insertFront(T newData) {
        Node<T>* newNode = createNode(newData);
        
        newNode->next = head;
        head = newNode;
        size++;
    }

    void deleteFront() {
        if (!isEmpty()) {
            Node<T>* tmp = head;
            head = head->next;
            delete tmp;
            size--;
        }  
        else cout << "List is empty\n\n";
    }

    void insertBack(T newData) {
        Node<T>* newNode = createNode(newData);
        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node<T>* tmp;
            for (tmp = head; tmp->next != nullptr; tmp = tmp->next);
            tmp->next = newNode;
        }
        size++;
    }

    void deleteBack() {
        if (!isEmpty()) {
            Node<T>* tmp = head;

            if (size == 1) {
                head = nullptr;
                delete tmp;
            }
            else {
                while (tmp->next->next != nullptr) tmp = tmp->next;
                delete tmp->next;
                tmp->next = nullptr;
            }
            size--;
        }
        else cout << "List is empty\n\n";
    }

    void insertSorted(T newData) {
        Node<T>* newNode = createNode(newData);
        if (isEmpty()) {
            head = newNode;
        }
        else if (head->data > newNode->data) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node<T>* tmp;
            for (tmp = head; (tmp->next != nullptr) && (tmp->next->data <= newNode->data); tmp = tmp->next);
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        size++;
    }

    void deleteNode(T data){        
        Node<T>* tmp = head;
        Node<T>* prev = head;

        if (!isEmpty()) {
            if (head->data == data) {
                head = head->next;
                size--;
                delete tmp;
            }
            else {
                while (tmp != nullptr) {
                    if (tmp->data == data) {
                        prev->next = tmp->next;
                        delete tmp;
                        size--;
                        break;
                    }
                    prev = tmp;
                    tmp = tmp->next;
                }
            }
        }
        else cout << "List is empty\n\n";
    }

    void print() {
        if (!isEmpty()) {
            cout << "List\n";
            /*
            Node<T>* tmp = head;
            while (tmp != nullptr) {
                cout << tmp->data << "\t";
                tmp = tmp->next;
            }
            */
                        
            for (Node<T>* tmp = head; tmp!= nullptr; tmp = tmp->next) {
                cout << tmp->data << "\t";
            }            
            cout << "\n";
        }
        else cout << "List is empty\n\n";
    }

};
