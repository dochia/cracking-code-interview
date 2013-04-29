#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int main(int argc, char *argv[])
{
  node* radacina = NULL;
  insertNode(&radacina, 6);
  insertNode(&radacina, 4);
  insertNode(&radacina, 8);
  insertNode(&radacina, 7);
  insertNode(&radacina, 9);
  insertNode(&radacina, 1);
  insertNode(&radacina, 5);
  printTree(radacina);
  printf("\nNo levels = %d\n", computeNoLevels(radacina));
  isTreeBalanced(radacina);
  system("PAUSE");	
  return 0;
}
