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

    void insertFront(T newData) {
        Node<T>* newNode = createNode(newData);
        
        newNode->next = head;
        head = newNode;
        size++;
    }

    bool exists(T data) {
        for (Note<T> tmp = head; tmp != NULL; tmp = tmp->next) {
            if (tmp->data == data) return true;
        }
        return false;
    }

    Node<T> find(T data) {
        for (Note<T> tmp = head; tmp != NULL; tmp = tmp->next) {
            if (tmp->data == data) return tmp;
        }
        return nullptr;
    }

    void deleteFront() {
        if (!isEmpty()) {
            Node<T>* tmp = head;
            head = head->next;
            free(tmp);
        }        
    }

    void insertBack(T newData) {
        Node<T>* newNode = createNode(newData);
        if (isEmpty()) {
            head = newNode;
        }
        else {
            Node<T>* tmp;
            for (tmp = head; tmp->next != NULL; tmp = tmp->next);
            tmp->next = newNode;
        }
        size++;
    }

    void deleteBack() {
        if (!isEmpty()) {
            Node<T>* tmp = head;

            if (size == 1) {
                head = head->next;
                free(tmp);
            }
            else {
                for (tmp = head; tmp->next != NULL; tmp = tmp->next);
            }
        }
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
            for (tmp = head; (tmp->next != NULL) && (tmp->next->data <= newNode->data); tmp = tmp->next);
            newNode->next = tmp->next;
            tmp->next = newNode;
        }
        size++;
    }
    

    void print() {
        if (!isEmpty()) {
            cout << "List\n";
            /*
            Node<T>* tmp = head;
            while (tmp != NULL) {
                cout << tmp->data << "\t";
                tmp = tmp->next;
            }
            */
                        
            for (Node<T>* tmp = head; tmp!=NULL; tmp = tmp->next) {
                cout << tmp->data << "\t";
            }            
            cout << "\n";
        }
        else cout << "List is empty\n\n";
    }

};
