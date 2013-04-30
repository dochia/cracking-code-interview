#include <cstdlib>
#include <iostream>
#include "DirectedGraph.h"

using namespace std;

int main(int argc, char *argv[])
{
    DirectedGraph g;
    for (int i = 0; i < 10; i++)
    {
        g.addVertex(i);
    }
    g.addArc(0, 1);
    g.addArc(0, 2);
    g.addArc(0, 7);
    g.addArc(0, 8);
    g.addArc(1, 3);
    g.addArc(1, 2);
    g.addArc(3, 5);
    g.addArc(3, 6);
    g.addArc(3, 7);
    g.addArc(4, 6);
    g.addArc(5, 4);
    g.addArc(6, 2);
    g.addArc(6, 5);
    g.addArc(7, 3);
    g.addArc(7, 6);
    g.addArc(7, 8);
    g.addArc(8, 0);
    if (g.isSReachableFromT(8,3))
    {
        printf("3 can be reached from 8.\n");
    }
    else
    {
        printf("3 cannot be reached from 8.\n");
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
