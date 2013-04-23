#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <set>
#include "MyStack.h"

using namespace std;

MyStack::MyStack(int capacity)
{
       this->mStack = new stack<int>();
       initialize(capacity); 
}

void MyStack::initialize(int capacity)
{     
     int value;
     for (int i = 0; i < capacity; i++)
     {
         value = i * 21 ;
         if (i % 2 == 0)
         {
               value += 17;   
         }
         else
         {
             value -= 17;
         }
         cout << "Adding value " << value << " to stack.\n";
         this->Push(value);
     }
}

void MyStack::Push(int value) 
{
     mStack->push(value);
}

void MyStack::Pop()
{
     mStack->pop();
}

int MyStack::Top()
{
    return mStack->top();
}

bool MyStack::IsEmpty()
{
     return mStack->empty();
}

void MyStack::OrderAscending()
{
     stack<int>* aux = new stack<int>();
     int temp;
     while (!this->IsEmpty())
     {
           temp = this->Top();
           this->Pop();
           while (!aux->empty() && aux->top() > temp)
           {
                 this->Push(aux->top());
                 aux->pop();
           }
           aux->push(temp);
     }  
     while (!aux->empty())
     {
           this->Push(aux->top());          
           aux->pop(); 
     } 
}

void MyStack::PrintStack()
{
     while (!this->IsEmpty())
     {
           cout << " " << this->Top();
           this->Pop();
     }
     cout << endl;
}
