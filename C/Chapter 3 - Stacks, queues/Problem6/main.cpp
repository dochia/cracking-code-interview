#include <cstdlib>
#include <iostream>
#include "MyStack.h"

using namespace std;

int main(int argc, char *argv[])
{
    MyStack m(5);
    m.OrderAscending();
    m.PrintStack(); 
    system("PAUSE");
    return EXIT_SUCCESS;
}
