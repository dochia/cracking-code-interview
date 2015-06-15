#include "Problem5.h"

void runProblem5Reverse()
{
     printf("REVERSE\n");
     node* a1 = createListFromNumberReverse(123);
     printListToConsole(a1);
     
     printf("\n");
     node* a2 = createListFromNumberReverse(123);
     printListToConsole(a2);
     
     printf("\n");
     node* sum1  = (node*) malloc(sizeof(node));
     sum1 = calculateSumReverse(a1, a2);
     printListToConsole(sum1);
     
     system("pause");
     free(a1);
     free(a2);
     free(sum1);
}

void runProblem5Forward()
{     
     printf("FORWARD\n"); 
     node* b1 = (node*) malloc(sizeof(node));
     b1 = createListFromNumberForward(123);
     printListToConsole(b1);
     
     printf("\n");
     node* b2 = (node*) malloc(sizeof(node));
     b2 = createListFromNumberForward(9999);
     printListToConsole(b2);
     
     printf("\n");
     node* sum2 = (node*) malloc(sizeof(node));
     sum2 = calculateSumForward(b1, b2);
     printListToConsole(sum2);
     
     free(b1);
     free(b2);
     free(sum2);
}

node* createListFromNumberReverse(int n)
{
      node* head = (node*) malloc(sizeof(node));
      head = NULL;
      while (n > 0)
      {
            insertNodeAtEnd(&head, n % 10);
            n /= 10;
      } 
      return head;
}

node* createListFromNumberForward(int n)
{
      node* head = (node*) malloc(sizeof(node));
      head = NULL;
      while (n > 0)
      {
            insertNodeAtBeginning(&head, n % 10);
            n /= 10;
      } 
      return head;
}

node* calculateSumReverse(node* a, node* b)
{
      node* sum = (node*) malloc(sizeof(node));
      sum = NULL;
      node* p = a;
      node* q = b;
      int carry = 0;
      while (q != NULL || p != NULL || carry != 0)
      {
            if (q != NULL)
            {
                  carry += q->data;
                  q = q->next;
            }
            if (p != NULL)
            {
                  carry += p->data;
                  p = p->next;
            }
            insertNodeAtEnd(&sum, carry % 10);
            carry /= 10;
      }
      return sum;
}

node* padWithZeroInTheBeginning(node** head, int len)
{
      int counter;
      for (counter = 0; counter < len; counter++)
      {
          insertNodeAtBeginning(head, 0);
      }
      printListToConsole(*head);
      return *head;
}

node* calculateSumForward(node* a, node* b)
{
      int lenA = countNodes(a);
      int lenB = countNodes(b);
      
      // pad the shorter list with 0
      if (lenA < lenB)
      {
         a = padWithZeroInTheBeginning(&a, lenB - lenA);
      }
      else
      {
         b = padWithZeroInTheBeginning(&b, lenA - lenB);
      }
      
      // add lists
      
      partialSum p = {.pSum = (node*)malloc(sizeof(node)), .carry = 0};
      p.pSum = NULL;
      p = addSumForwardHelper(a, b);
      if (p.carry == 0)
      {
          return p.pSum;
      }
      else
      {
          insertNodeAtBeginning(&(p.pSum), p.carry % 10);
          return p.pSum;
      }
}

partialSum addSumForwardHelper(node* a, node* b)
{
           if (a == NULL && b == NULL)
           {
                 partialSum temp = {(node*) malloc(sizeof(node)), 0};
                 temp.pSum = NULL;
                 temp.carry = 0;
                 return temp;
           }           
           partialSum temp = addSumForwardHelper(a->next, b->next);
           
           int val = temp.carry + a->data + b->data;
           
           insertNodeAtBeginning(&(temp.pSum), val % 10);
           temp.carry = val / 10;
           
           return temp;
}
