#include "SetOfStacks.h"
#include <iostream>

using namespace std;

SetOfStacks::SetOfStacks(int stackCapacity)
{
            cout << "Initializing set of stacks... " << endl;           
            this->mStackCapacity = stackCapacity;
            cout << "The set contains " << this->mStacks.size() << " stacks." << endl;
}

void SetOfStacks::Push(int value)
{
     int len = this->mStacks.size();
     // verify if there is a stack that hasn't reached capacity
     if (len == 0 || this->mStacks[len - 1].size() == mStackCapacity)
     {
         cout << "Adding a new stack... \n";
         stack<int> st;
         st.push(value);
         this->mStacks.push_back(st);        
         len = this->mStacks.size();
         cout << "Adding value " << value << " to stack no "<<  len  << ".\n"; 
     }
     else
     {
         cout << "Adding value " << value << " to stack no "<<  len  << ".\n"; 
         this->mStacks[len-1].push(value);
     }

}

int SetOfStacks::Pop()
{
    int len = this->mStacks.size();
    int value = this->mStacks[len-1].top();
    this->mStacks[len-1].pop();
    cout << "Removing element with value " << value << " from stack no " << len << ".\n";
    if (this->mStacks[len-1].size() == 0)
    {
        this->mStacks.pop_back();
    }
    return value;
    
}

int SetOfStacks::PopAt(int index)
{
     stack<int> tempStack;
     int len = this->mStacks.size();
     int value = this->mStacks[index-1].top();
     this->mStacks[index-1].pop();
     cout << "Removing element with value " << value << " from stack no " << index << ".\n";
     while (len != index)
     {
           value = this->mStacks[len-1].top();
           tempStack.push(value);
           this->Pop();
           len = this->mStacks.size();
     }
     while (!tempStack.empty())
     {
           value = tempStack.top();
           tempStack.pop();
           this->Push(value);
     }
     
}
