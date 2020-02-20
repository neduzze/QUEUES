//
// Created by neduzze on 1/26/20.
//
#pragma once

#include <iostream>

#define MAX_SIZE 101
using namespace std;

class My_Queue {
private:
    int front, rear;
    int A[MAX_SIZE]{};
private:
    static void infoMessage(int x);

public:
    My_Queue();

    bool isEmpty();

    bool isFull();

    void Enqueue(int x);

    int Dequeue();

    int Front();

    void print();

};


