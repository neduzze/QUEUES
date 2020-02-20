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

