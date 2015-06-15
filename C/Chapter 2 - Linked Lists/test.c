#include "linkedList.h"

void test()
{
  node* p = (node*) malloc(sizeof(node));
  p = NULL;
  
  printf("%d \n",isListEmpty(p));
  system("pause");
  
  insertNodeAtBeginning(&p, 10);
  insertNodeAtBeginning(&p, 9);
  insertNodeAtBeginning(&p, 4);
  insertNodeAtBeginning(&p, 2);
  insertNodeAtBeginning(&p, 7);
  insertNodeAtEnd(&p, 12);
  insertNodeAtEnd(&p, 15);
  printf("No nodes = %d \n", countNodes(p));
  insertNodeAtPositionFromBeginning(&p, 0, 35);
  insertNodeAtPositionFromBeginning(&p, 2, 68);
  
  printListToConsole(p);
  system("pause");

  deleteNodeWithValue(&p, 10);
  deleteNodeWithValue(&p, 2);
  deleteNodeWithValue(&p, 35);
  deleteNodeWithValue(&p, 351);
  
  printListToConsole(p);
  system("PAUSE");
  
  printf("%d \n",isListEmpty(p));
  system("pause");
  
  printf("%d \n", deleteNode(&p, p));
  system("pause");
  
  free(p);
}
