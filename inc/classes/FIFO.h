#pragma once
#include <cstddef>
#include <stdexcept>
#include <iostream>
// Node structure (templated)
template <typename T>
struct Node {
    T data;
    Node* next;
};

struct ComputationData {
    char op;
    int operand1;
    int operand2;
};

// FIFO Queue class (templated)
template <typename T>
class FIFO {
private:
    Node<T>* front;
    Node<T>* rear;

    uint32_t size = 0;

public:
    // Constructor
    FIFO() {
        front = rear = nullptr;
    }

    // Destructor
    ~FIFO() {
        while (front != nullptr) {
            pop();
        }
    }

    // Push method — adds a value to the end of the queue
    void push(const T& value) {
        Node<T>* newNode = new Node<T>();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }

    // Pop method — removes and returns the value from the front of the queue
    T pop() {
        if (front == nullptr) {
            throw std::underflow_error("Queue underflow. Cannot pop from an empty queue.");
        }

        Node<T>* temp = front;
        T value = temp->data;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
        size--;
        return value;
    }

    T getFront(){
        return front;
    }

    // Search method — returns true if value is found, false otherwise
    bool search(const T& value) const {
        Node<T>* current = front;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Display the queue (for debugging)
    void display() const {
        Node<T>* current = front;
        std::cout << "FIFO: ";
        while (current != nullptr) {
            std::cout << *current->data << " -> ";
            current = current->next;
        }
        std::cout << "NULL\n";
    }

    uint32_t getSize(){
        return size;
    }
};