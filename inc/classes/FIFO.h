#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>

template <typename T>
struct Node {
    T* data;
    Node* next;
};

template <typename T>
class FIFO {
private:
    Node<T>* front;
    Node<T>* rear;
    size_t count;

public:
    FIFO() : front(nullptr), rear(nullptr), count(0) {}

    ~FIFO() {
        while (front != nullptr) {
            pop();
        }
    }

    void push(T* ptrValue) {
        Node<T>* newNode = new Node<T>();
        newNode->data = ptrValue;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        count++;
    }

    T pop() {
        if (front == nullptr) {
            throw std::underflow_error("Empty queue: cannot pop");
        }

        Node<T>* temp = front;
        T value = *temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        count--;
        return value;
    }

    size_t size() const {
        return count;
    }

    void display() const {
        Node<T>* current = front;
        while (current != nullptr) {
            std::cout << *current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }
};