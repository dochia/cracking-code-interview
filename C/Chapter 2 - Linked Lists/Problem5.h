#include "linkedList.h"

typedef struct PartialSum{
    node* pSum;
    int carry;    
} partialSum;

void runProblem5Reverse();

void runProblem5Forward();

node* createListFromNumberReverse(int n);

node* createListFromNumberForward(int n);

node* calculateSumReverse(node* a, node* b);

node* padWithZeroInTheBeginning(node** head, int len);

node* calculateSumForward(node* a, node* b);

partialSum addSumForwardHelper(node* a, node* b);
