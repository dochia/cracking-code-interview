#include "Problem6.h"
#include "Problem2.h"

void runProblem6()
{
     node* p = (node*)malloc(sizeof(node));
     p = NULL;
     
     insertNodeAtEnd(&p, 1);
     insertNodeAtEnd(&p, 5);
     insertNodeAtEnd(&p, 7);
     insertNodeAtEnd(&p, 12);
     insertNodeAtEnd(&p, 18);
     insertNodeAtEnd(&p, 3);
     
     //printListToConsole(p);
     
     node* aux = findKthElementOfEnd(p, 1);
     node* temp = findKthElementOfEnd(p, 5);
     aux->next = temp;
     
     findLoop(p);
     //printListToConsole(p);
     //system("pause");
     
     free(p);    
}

node* findLoop(node* head)
{
      node* p, *q;
      p = head;
      q = head;
      while (p!= NULL && q!= NULL)
      {
            p = p->next;
            q = q->next->next;
            if (p == q)
            {
                  break;
            }
      }
      if (p == NULL || q == NULL)
      {
            printf("List doesn't have a loop\n");
            return NULL;
      }
      else
      {
          printf("P reached %d, Q reached %d.\n", p->data, q->data);
          p = head;
          while (p != q)
          {
                p = p -> next;
                q = q -> next;
          }
          printf("List has a loop - starting node with data %d.\n", q->data); 
          return q;
      }
}
