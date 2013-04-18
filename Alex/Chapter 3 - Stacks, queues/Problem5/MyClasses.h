#include <iostream>
#include <stack>
using namespace std;

class MyQueue
{
      private:
              stack<int> S1, S2;
              void MoveS1ToS2();
      public:
             void Enqueue(int value);
             int Dequeue();
             void PrintQueue();
              
};
