#include "Problem3.h"
#include "Problem2.h"

void runProblem3()
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
     
     node* aux = findKthElementOfEnd(p, 3);
     system("pause");
     deleteNodeInMiddle(aux);
     
     printListToConsole(p);
     
     free(p);
}

int deleteNodeInMiddle(node* toDelete)
{
    node* p = toDelete;
    node* aux = (node*) malloc(sizeof(node));
    if (p ->next != NULL)
    {
          aux = p->next;
          p->data = aux->data;
          p->next = aux->next;
          free(aux);
          return 1;
    }
    else
    {
        printf("deleteNodeInMiddle: Trying to delete the last node in the list.\n");
        return 0;
    }
}
