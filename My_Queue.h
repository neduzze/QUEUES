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
public:
    My_Queue();
    int Front();
    void print();
    bool isEmpty();
    bool isFull();
    void Enqueue(int x);
    int Dequeue();
    void demo();
    static void infoMessage(int x);
};

class MyLinkedListQueue{
    //Private variables
private:
    struct Node{
        int data;
        Node* next;
    };
    //initializing front and rear
    Node* front;
    Node* rear;
    //private functions
private:
    int Front();
    bool IsEmpty();
    void printQueue();

public:
    MyLinkedListQueue();
    void demo();
    void Enqueue(int x);
    int Dequeue();
};
