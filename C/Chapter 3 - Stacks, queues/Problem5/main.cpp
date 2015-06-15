#include <cstdlib>
#include <iostream>
#include "MyClasses.h"

using namespace std;

int main(int argc, char *argv[])
{
    MyQueue mq;
    mq.Enqueue(1);
    mq.Enqueue(2);
    mq.Enqueue(3);
    mq.Dequeue();
    mq.Enqueue(4);
    mq.PrintQueue();
    system("PAUSE");
    return EXIT_SUCCESS;
}
