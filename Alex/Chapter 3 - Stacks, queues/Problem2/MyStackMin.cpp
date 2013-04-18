#include <iostream>
#include "MyStackMin.h"

using namespace std;

MyStackMin::MyStackMin(int Capacity)
{
    this->mCapacity = Capacity;
    this->mArr = (int*) malloc(sizeof(int) * Capacity);                 
    this->mMinLength = 1;
    this->mLength = 0;
    this->mMinValues = (int*)malloc(sizeof(int) * 1);
    this->mMinValues[0] = -1;
}

int MyStackMin::FindMin()
{
    return this->mMinValues[this->mMinLength - 1];
}

int MyStackMin::AddValue(int Value)
{
    if (this->mCapacity == this->mLength)
    {
                       
        throw "Capacity has been reached.\n";
    }
    this->mArr[this->mLength] = Value;
    this->mLength++;
    return 1;
}

void MyStackMin::Push(int Value)
{
     cout << "Adding value " << Value << " to the stack. \n";
     // verifica daca min este mai mare decat value
     int currentMin = this->FindMin();
     if ( currentMin > Value || currentMin == -1)
     {
         this->mMinLength++;
         this->mMinValues = (int*) realloc(this->mMinValues, sizeof(int) * this->mMinLength); 
         this->mMinValues[this->mMinLength-1] = Value;
     }
     // adauga value in stack
     this->AddValue(Value);
     //  
     this->PrintStack(); 
}

int MyStackMin::Pop()
{
    this->mLength--;
    int value = this->mArr[this->mLength];
    cout << "Removing the last element in the stack - " << value << endl;
    if (FindMin() == value)
    {
                  this->mMinLength--;
                  this->mMinValues = (int*) realloc(this->mMinValues, sizeof(int) * this->mMinLength);
    }
    return value;
}

void MyStackMin::PrintStack()
{
     int i = 0;
     cout << "Values in stack are:" ; 
     for (i = 0; i < this->mLength; i++)
     {
         cout << " " << this->mArr[i];
     }
     cout << endl << "Min values are:";
     for (i = 0; i < this->mMinLength; i++)
     {
         cout << " " << this->mMinValues[i]; 
     }
     cout << endl;
     
}
