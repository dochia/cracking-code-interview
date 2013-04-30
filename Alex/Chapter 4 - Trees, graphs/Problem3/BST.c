#include "BST.h"
#include <stdio.h>

TreeNode* createMinimalBST(int arr[], int len)
{
     printf("len = %d\n", len);
     return createBST(arr, 0, len-1);
}

TreeNode* createBST(int arr[], int start, int end)
{
     if (end < start)
     {
        return NULL;       
     }
     int mid = (start + end) / 2;
     TreeNode* aux = (TreeNode*)malloc(sizeof(TreeNode));
     aux->info = arr[mid];
     aux->left = createBST(arr, start, mid-1);
     aux->right = createBST(arr, mid+1, end);
     return aux;
}

void printPreOrder(TreeNode* start)
{
     if (start != NULL)
     {
        printf("%d ", start->info);
        printPreOrder(start->left);
        printPreOrder(start->right);
     }
}

void printInOrder(TreeNode* start)
{
     if (start != NULL)
     {
        printInOrder(start->left);
        printf("%d ", start->info);
        printInOrder(start->right);
     }
}

void printPostOrder(TreeNode* start)
{
     if (start != NULL)
     {
         printPostOrder(start->left);
         printPostOrder(start->right);
         printf("%d ", start->info);
     }
}
