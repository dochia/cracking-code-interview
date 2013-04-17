#include <cstdlib>
#include <iostream>
#include "FixedLength.h"
#include <exception>

using namespace std;

int main(int argc, char *argv[])
{
    try 
    {
        MyStack* my = new MyStack(9);
        my->push(0, 4);
        my->push(0, 3);
        my->push(0, 9);
        my->push(1, 67);
        my->push(1, 45);
        my->push(1, 36);
        my->push(2, 142);
        my->push(2, 345);
        cout << my->peek(2);
        my->push(2, 876);
        my->push(2, 876);
        my->printStacks();        
        my->pop(0);
        my->pop(1);
        my->pop(1);
        my->pop(2);
        my->printStacks();
        
    }
    catch(char* str ) {
      printf("\nException Raised: %s \n", str);
   }
   system("PAUSE");
   return 0;
}
