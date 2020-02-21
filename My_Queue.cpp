//
// Created by neduzze on 1/26/20.
//

#include <iostream>
#include "My_Queue.h"

using namespace std;


My_Queue::My_Queue() {
    front = -1;
    rear = -1;
}

bool My_Queue::isEmpty() {
    return (front == rear && front == -1);
}

bool My_Queue::isFull() {
    return (rear + 1) % MAX_SIZE == front;
}


void My_Queue::Enqueue(int x) {
    if (isFull()) {
        infoMessage(0);
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        //rear++; for a linear queue

        //for a cyclical queue
        rear = (++rear) % MAX_SIZE;
    }
    A[rear] = x;
    print();
}


int My_Queue::Dequeue() {
    int returnVal = Front();
    if (isEmpty()) {
        infoMessage(1);
        return -1;
    } else if (front == rear) {
        front = rear = -1;
    } else {
        front = (++front) % MAX_SIZE;
    }
    cout << returnVal << " has been dequeued\n";
    print();
    return returnVal;
}

int My_Queue::Front() {
    if (front == -1)
        return -1;
    else
        return A[front];
}

void My_Queue::print() {
    int n = (rear + MAX_SIZE - front) % MAX_SIZE + 1;
    if (isEmpty()) {
        infoMessage(1);
        return;
    }
    cout << "Queue: ";
    for (int i = 0; i < n; i++) {
        int index = (front + i) % MAX_SIZE;
        cout << A[index] << " ";
    }
    cout << "\n";
}

void My_Queue::infoMessage(int x) {
    switch (x) {
        case 0:
            cout << "[INFO!] Queue is Full!\n";
            break;
        case 1:
            cout << "[INFO!]Queue is Empty!\n";
            break;
        case 2:
            cout << "[ERROR! ...]\n";
            break;
        default:
            cout << "Debug\n";
    }
}

void My_Queue::demo() {
    Enqueue(4);
    Enqueue(5);
    Enqueue(6);
    Enqueue(7);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Enqueue(6);
    Enqueue(7);
    Enqueue(6);
    Enqueue(7);

}

//functions for Linked list class
MyLinkedListQueue::MyLinkedListQueue() {
    front = nullptr;
    rear = nullptr;
}

void MyLinkedListQueue::Enqueue(int x) {
    Node *temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    if (front == nullptr && rear == nullptr) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
    printQueue();
}

int MyLinkedListQueue::Dequeue() {
    Node *temp = front;
    int returnVal = front->data;
    if (front == nullptr && rear == nullptr) {
        My_Queue::infoMessage(1);
        return -1;
    }
    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
    }
    printQueue();
    delete temp;
    return returnVal;
}


int MyLinkedListQueue::Front() {
    if (IsEmpty())
        return -1;
    else
        return front->data;
}

bool MyLinkedListQueue::IsEmpty() {
    return (front == nullptr && rear == nullptr);
}

void MyLinkedListQueue::printQueue() {
    if (IsEmpty()) {
        My_Queue::infoMessage(1);
        return;
    }
    Node *temp = front;
    cout << "Queue: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

void MyLinkedListQueue::demo() {
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
    Dequeue();
}

