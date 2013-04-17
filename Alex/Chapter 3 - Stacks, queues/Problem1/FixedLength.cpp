#include "FixedLength.h"
using namespace std;

MyStack::MyStack(int capacity)
{
       this->StackLength = capacity / 3;
       this->Capacity = capacity;
       this->StacksCounter = (int*) malloc(sizeof(int) * 3);
       int i = 0;
       for (i = 0; i < this->StackLength; i++)
       {
           this->StacksCounter[i] = -1;
       }
       this->S = (int*) malloc(sizeof(int) * capacity);
       for (i = 0; i < capacity; i++)
       {
           this->S[i] = -1;
       }
}

bool MyStack::isEmpty(int stackNo){
       return (this->S == NULL);
}

void MyStack::push(int stackNo, int value) throw (char*)
{
     if (this->StacksCounter[stackNo] == this->StackLength - 1)
     {
         char* s;
         sprintf(s, "Item %d cannot be added to stackNo %d, reached maximum lenght", value, stackNo);
         throw s;
     }
     else
     {
         this->StacksCounter[stackNo] += 1 ;
         int actualIndex = computeIndex(stackNo);
         this->S[actualIndex] = value;
         
     }
}

int MyStack::pop(int stackNo){
       int actualIndex = computeIndex(stackNo);
       int value = this->S[actualIndex];
       this->S[actualIndex] = -1;
       this->StacksCounter[stackNo]--;
       return value;
}

int MyStack::peek(int stackNo){
    int actualIndex = computeIndex(stackNo);
    return this->S[actualIndex];
}

int MyStack::computeIndex(int stackNo){
    return ( stackNo * this->StackLength + this->StacksCounter[stackNo]);
}

void MyStack::printStacks(){
     int i = 0;
     for (i = 0; i < 3; i++)
     {
         this->printStack(i);
     }  
}
void MyStack::printStack(int stackNo){
     int i = 0;
     bool aux = false;
     for (i = 0; i <= this->StacksCounter[stackNo]; i++)
     {
         int value = this->S[stackNo * this->StackLength + i];
         if (value != -1)
         {
             cout << value << " "; 
             aux = true;
         }
     }
     if (aux) 
     {
              cout << endl;
     }
}
