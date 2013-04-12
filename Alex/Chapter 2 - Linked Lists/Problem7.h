#include "linkedList.h"
#include <stdbool.h>

typedef struct ResultPalindrome
{
        node* next;
        bool res;
} resultPalindrome;

void runProblem7();

bool isListPalindromeIterative(node* head);

bool isListPalindromeRecursive(node* head);

resultPalindrome recursePalindromeHelper(node* head, int len);
