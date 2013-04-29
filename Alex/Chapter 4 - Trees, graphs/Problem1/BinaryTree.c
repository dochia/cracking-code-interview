#include "BinaryTree.h"
#include <stdio.h>
//#include <ctype>

void destroyTree(node* root)
{
     if (root != NULL)
     {
              destroyTree(root->left);
              destroyTree(root->right);
              free(root);
     }
}

int insertNode(node** root, int value)
{
    if (*root == NULL)
    {
        printf("Inserting node with value %d\n", value);
        *root = (node*) malloc(sizeof(node));
        (*root)->info = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else if ((*root)->info > value)
         {
             insertNode(&((*root)->left), value);         
         }
         else if ((*root)->info <= value)
         {
              insertNode(&((*root)->right), value);
         }
}

void printTree(node* root)
{
    int levels = computeNoLevels(root);
    int cols = 3 * (4 * levels - 3);
    int rows = 2 * levels - 1;
    printf("MATRIX %d X %d\n", cols, rows);
    char* printer = (char*) malloc(sizeof(char) * rows * cols);
    int i, j;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols - 1; j++)
        {
            printer[i*cols + j] = ' ';    
        }
        printer[i*cols + cols] = '\n';
    }
    printTreeHelper(root, printer, cols, 0, cols / 2, false );
    
    //printf("\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols ; j++)
        {
            printf("%c",printer[i*cols + j]);    
        }
        printf("\n");
    }
    free(printer);
}

void printTreeHelper(node* root, char* printer, int cols, int row, int col, bool left)
{
     printf("Apelam helper cu parametrii cols = %d, row = %d, col = %d\n", cols, row, col);
     if (root != NULL)
     {
        if (root->left == NULL && root->right == NULL )
        {
           if (left)
           {      
               printer[row * cols + col + 1] = '0' + root->info;
           } 
           else
           {
               printer[row * cols + col - 1] = '0' + root->info;               
           }
        }
        else
        {
            printf("Afisam root row = %d, col = %d\n", row, col);
            printer[row * cols + col] = '0' + root->info; 
        }
        if (root->left != NULL)
        {
            printf("Afisam / row = %d, col = %d\n", row + 1, col - 2);           
            printer[(row + 1) * cols + col - 2] = '/';   
            printTreeHelper(root->left, printer, cols, row + 2, col - 3, true);
        }
        if (root->right != NULL)
        {
            printf("Afisam \\ row = %d, col = %d\n", row + 1, col + 2);           
            printer[(row + 1) * cols + col + 2 ] = '\\';
            printTreeHelper(root->right, printer, cols, row + 2, col + 3, false);
        }
     }  
} 

int computeNoLevels(node* root)
{
    if (root == NULL)
    {
             return 0;
    }
    else
    {
        int left = computeNoLevels(root->left);
        int right = computeNoLevels(root->right);
        
        if (left < right) 
        {
           return right + 1;
        }
        else if (left >= right)
             {
                 return left + 1;
             }
    }
}

int minHeight(node* root)
{
    if (root == NULL)
    {
             return 0;
    }
    else
    {
        return 1 + MIN(minHeight(root->left), minHeight(root->right));
    }
}

int maxHeight(node* root)
{
    if (root == NULL)
    {
             return 0;
    }
    else
    {
        return 1 + MAX(maxHeight(root->left), maxHeight(root->right));
    }
}

bool isTreeBalanced(node* root)
{
     bool result = (maxHeight(root) - minHeight(root) <= 1); 
     if (result) 
     {
        printf("The tree is balanced.\n");
     }
     else
     {
        printf("The tree is not balanced.\n");
     }
     return result;
}
