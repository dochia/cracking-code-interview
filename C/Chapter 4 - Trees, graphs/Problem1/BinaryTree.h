#include <stdbool.h>

#define MIN(a,b) (((a)<=(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

typedef struct Node{
       int info;
       struct Node* left;
       struct Node* right;
}node;


void destroyTree(node* root);

int insertNode(node** root, int value);

void printTree(node* root);

void printTreeHelper(node* root, char* printer, int rows, int row, int col, bool left);

int computeNoLevels(node* root);

bool isTreeBalanced(node* root);
