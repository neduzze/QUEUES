#include <iostream>
#include "My_Queue.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    My_Queue E;
    E.Enqueue(4);
    E.print();
    E.Enqueue(5);
    E.print();
    E.Enqueue(6);
    E.print();
    E.Enqueue(7);
    E.print();
    E.Dequeue();
    E.print();
    E.Dequeue();
    E.print();
    E.Dequeue();
    E.print();
    E.Dequeue();
    E.print();
    E.Enqueue(6);
    E.print();
    E.Enqueue(7);
    E.print();
    E.Enqueue(6);
    E.print();
    E.Enqueue(7);
    return 0;
}
