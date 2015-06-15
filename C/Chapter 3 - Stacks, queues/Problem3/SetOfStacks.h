#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class SetOfStacks
{
      private:
              vector< stack<int> > mStacks;
              int mStackCapacity;
      public:
             SetOfStacks(int stackCapacity);
             void Push(int value);
             int Pop();
             int PopAt(int index);
           
};
