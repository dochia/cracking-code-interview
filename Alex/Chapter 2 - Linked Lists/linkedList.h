#include <stdlib.h>
#include <stdio.h>

typedef struct Node{
        int data;
        struct Node* next;
} node;

int insertNodeAtTheEnd(node** head, int value);

int insertNodeAtBeginning(node** head, int value);

int insertNodeAtPositionFromBeginning(node** head, int position, int value);

int deleteNodeWithValue(node** head, int value);

int countNodes(node* head);

int insertNodeAtEnd(node** head, int value);

int printListToConsole(node* head);
