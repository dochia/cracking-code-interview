#ifndef PROBLEM1_FIXEDLENGHT_H
#define PROBLEM1_FIXEDLENGHT_H

class MyStack
{
      private:
              int maxLenght;
              int* S;
              int* noElements;
              int computeIndex(int stackNo);
      public:
             MyStack(int maxElements);
             void push(int stackNo, int value);
             int pop(int stackNo);
             int peek(int stackNo);
             bool isEmpty(int stackNo);
};

#endif
