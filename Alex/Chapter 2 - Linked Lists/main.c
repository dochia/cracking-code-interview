#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

int main(int argc, char *argv[])
{
  node* p;
  p = NULL;
  
  printf("%d \n", insertHead(&p, 10));
  printf("%d \n", insertNodeAtBeginning(&p, 9));
  printf("%d \n", insertNodeAtBeginning(&p, 4));
  printf("%d \n", insertNodeAtBeginning(&p, 2));
  printf("%d \n", insertNodeAtBeginning(&p, 7));
  printf("%d \n", insertNodeAtEnd(&p, 12));
  printf("No nodes = %d \n", countNodes(p));
  printf("%d \n", insertNodeAtPositionFromBeginning(&p, 5, 35));
  printf("%d \n", insertNodeAtPositionFromBeginning(&p, 2, 68));
  
  system("pause");

  printf("%d \n", printListToConsole(p));
  
  printf("%d \n", deleteNodeWithValue(&p, 7));
  printf("%d \n", deleteNodeWithValue(&p, 2));
  printf("%d \n", deleteNodeWithValue(&p, 35));
  printf("%d \n", deleteNodeWithValue(&p, 351));
  
  printf("%d \n", printListToConsole(p));
  
  system("PAUSE");	
  return 0;
}
