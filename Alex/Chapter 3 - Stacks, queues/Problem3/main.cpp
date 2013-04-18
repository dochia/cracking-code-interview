#include <cstdlib>
#include <iostream>
#include "SetOfStacks.h"

using namespace std;

int main(int argc, char *argv[])
{
    SetOfStacks s(3);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    s.Push(4);
    s.Pop();
    s.Pop();
    s.Push(5);
    s.Push(6);
    s.Push(7);
    system("PAUSE");
    return EXIT_SUCCESS;
}
