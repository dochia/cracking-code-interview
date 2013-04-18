#include "MyClasses.h"

void MyQueue::MoveS1ToS2()
{
     int value;
     while (!S1.empty())
     {
           value = S1.top();
           S2.push(value);
           S1.pop();
     }
}

int MyQueue::Dequeue()
{
    int value = -1;
    if (S2.empty())
    {
       MoveS1ToS2();             
    }
    if (!S2.empty())
    {
          value = S2.top();
          S2.pop();
          cout << "Value " << value << " has been dequeued.\n"; 
    }
    else
    {
        cout << "There are no elements to be dequeued." << endl;
    }
    return value;
}

void MyQueue::Enqueue(int value)
{
     cout << "Value " << value << " has been enqueued. \n";
     S1.push(value);
}

void MyQueue::PrintQueue()
{
     int value = Dequeue(); 
     while (value != -1)
     {
           value = Dequeue();
     }
}
