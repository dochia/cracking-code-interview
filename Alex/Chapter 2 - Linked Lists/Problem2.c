#include "Problem2.h"

void runProblem2()
{
     node* p = (node*)malloc(sizeof(node));
     p = NULL;
     
     insertNodeAtEnd(&p, 1);
     insertNodeAtEnd(&p, 4);
     insertNodeAtEnd(&p, 9);
     insertNodeAtEnd(&p, 13);
     insertNodeAtEnd(&p, 5);
     insertNodeAtEnd(&p, 7);
     insertNodeAtEnd(&p, 12);
     insertNodeAtEnd(&p, 18);
     insertNodeAtEnd(&p, 3);
     
     printListToConsole(p);
     findKthElementOfEnd(p, 2);
     findKthElementOfEnd(p, 9);
     findKthElementOfEnd(p, 8);
     findKthElementOfEnd(p, 12);
          
     free(p);
}

node* findKthElementOfEnd(node* head, int k)
{
     node* p = head;
     node* q = head;
     int counter = 1;
     while (q != NULL && counter < k)
     {
            q = q->next;
            counter++;
     } 
     if (q != NULL)
     {
           while (q->next != NULL && p->next != NULL)
           {
                 q = q->next;
                 p = p->next;
           }
           if (p != NULL)
           {
                   printf("KthElementOfEnd: Kth element from the end is node with value %d.\n", p->data);
                   return p;
           }
           else
           {
               return NULL;
           }
     }
     else
     {
         printf("KthElementOfEnd: K is greater than the lenght of the list.\n");
         return NULL;
     }
}
