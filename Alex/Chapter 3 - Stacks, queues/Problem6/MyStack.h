#include <stack>

using namespace std;

class MyStack
{
      private:
              stack<int>* mStack;
              void initialize(int capacity);
      public:
             MyStack(int capacity);
             void Push(int value);
             void Pop();
             int Top();
             bool IsEmpty();   
             void OrderAscending();    
             void PrintStack(); // it will empty the stack     
};
