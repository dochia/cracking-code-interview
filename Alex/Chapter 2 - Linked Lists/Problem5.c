#include "Problem5.h"

void runProblem5()
{
     node* a1 = createListFromNumberReverse(123);
     printListToConsole(a1);
     
     node* a2 = createListFromNumberReverse(123);
     printListToConsole(a2);
     
     node* sum  = (node*) malloc(sizeof(node));
     sum = calculateSumReverse(a1, a2);
     printListToConsole(sum);
     
     node* b = createListFromNumberForward(1250);
     printListToConsole(b);
     
     free(a1);
     free(a2);
     free(sum);
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

node* calculateSumReverse(node* a, node* b)
{
      
      
}

