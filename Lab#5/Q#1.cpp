
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* front;
    Node<T>* rear;

    Node(T value) {
        data = value;
        front = nullptr;
        rear = nullptr;
    }
};

template <typename T>
class Deque {
private:
    Node<T>* front;
    Node<T>* rear;

public:
    Deque() {
        front = nullptr;
        rear = nullptr;
    }

    void insertFront(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (front == nullptr) {
            front = rear = newNode;
        } else {
            newNode->rear = front;
            front->front = newNode;
            front = newNode;
        }
    }

    void insertRear(T value) {
        Node<T>* newNode = new Node<T>(value);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->front = newNode;
            newNode->rear = rear;
            rear = newNode;
        }
    }

    void deleteFront() {
        if (front == nullptr) {
            throw underflow_error("Deque is empty");
        }

        Node<T>* temp = front;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            front = front->rear;
            front->front = nullptr;
        }

        delete temp;
    }

    void deleteRear() {
        if (rear == nullptr) {
            throw underflow_error("Deque is empty");
        }

        Node<T>* temp = rear;

        if (front == rear) {
            front = rear = nullptr;
        } else {
            rear = rear->front;
            rear->rear = nullptr;
        }

        delete temp;
    }

    void display() {
        Node<T>* temp = front;

        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->rear;
        }

        cout << endl;
    }
};

int main() {
    Deque<int> d;

    d.insertFront(20);
    d.insertFront(10);
    d.insertRear(30);
    d.insertRear(40);

    d.display();

    d.deleteFront();
    d.display();

    d.deleteRear();
    d.display();

    return 0;
}
