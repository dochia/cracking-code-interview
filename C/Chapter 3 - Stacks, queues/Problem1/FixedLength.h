#include <iostream>
#ifndef FIXEDLENGTH_H
#define FIXEDLENGTH_H

class MyStack
{
      public:
             int computeIndex(int stackNo);
             MyStack(int capacity);
             void push(int stackNo, int value) throw (char*);
             int pop(int stackNo);
             int peek(int stackNo);
             bool isEmpty(int stackNo);
             void printStacks();
             void printStack(int stackNo);
      private:
             int StackLength;
             int Capacity;
             int* S;
             int* StacksCounter;
};

#endif
