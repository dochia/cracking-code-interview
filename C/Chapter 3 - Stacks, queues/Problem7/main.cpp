#include <cstdlib>
#include <iostream>
#include "SystemStructures.h"

using namespace std;

int main(int argc, char *argv[])
{
    Cat* c1 = new Cat("Ana");
    Cat* c2 = new Cat("Bianca");
    Cat* c3 = new Cat("Crina");
    Cat* c4 = new Cat("Dorina");
    
    Dog* d1 = new Dog("Aurel");
    Dog* d2 = new Dog("Bogdanel");
    Dog* d3 = new Dog("Catanel");
    Dog* d4 = new Dog("Dorel");
    
    AnimalQueue aq;
    cout << " ADDING TO ANIMAL QUEUE \n";
    aq.enqueue(c1);
    aq.enqueue(d1);
    aq.enqueue(c2);
    aq.enqueue(d2);
    aq.enqueue(c3);
    aq.enqueue(d3);
    aq.enqueue(c4);
    aq.enqueue(d4);
   
    aq.dequeueAny();
    aq.dequeueCats();
    
    free(c1);
    free(d1);
    free(c2);
    free(d2);
    free(c3);
    free(d3);
    free(c4);
    free(d4);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
