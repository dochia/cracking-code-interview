#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

int main(int argc, char *argv[])
{
  int arr[] = {0, 1, 2, 3, 4, 5, 6, 7};
  TreeNode* root = createMinimalBST(arr, sizeof(arr)/sizeof(int));
  printf("\nPreOrder: ");
  printPreOrder(root);
  printf("\nInOrder: ");
  printInOrder(root);
  printf("\nPostOrder: ");
  printPostOrder(root);
  printf("\n");
  system("PAUSE");	
  return 0;
}
