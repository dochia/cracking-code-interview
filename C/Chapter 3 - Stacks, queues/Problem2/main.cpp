#include <cstdlib>
#include <iostream>
#include "MyStackMin.h"

using namespace std;

int main(int argc, char *argv[])
{
    try 
    {
        MyStackMin* my = new MyStackMin(10);
        my->Push(5);
        my->Push(10);
        my->Push(2);
        my->Pop();
        cout << my->FindMin() << endl;
    }
    catch (char* str)
    {
          cout << "Exception raised: " << str << endl;
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}
