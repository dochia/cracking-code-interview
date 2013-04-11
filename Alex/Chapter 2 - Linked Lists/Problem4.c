#include "Problem4.h"
#include "Problem2.h"

void runProblem4()
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
     
     rearrangeElements(&p, aux);
     printListToConsole(p);
     system("pause");
     
     free(p);
}     

void rearrangeElements(node** head, node* pivot)
{
     node* before = (node*) malloc(sizeof(node));
     node* after = (node*) malloc(sizeof(node));
     before = NULL;
     after = NULL;
     node* p = *head;
     node* q = NULL;
     while (p!= NULL)
     {
           if (p != pivot)
           {
                 if (p->data > pivot->data || p->data == pivot->data)
                 {
                     insertNodeAtEnd(&after, p->data);
                 }
                 else
                 {
                     // p.data < pivot.data
                     insertNodeAtEnd(&before, p->data);
                 }
           }
           p = p->next; 
     } 
     *head = before;
     p = after;
     insertNodeAtEnd(&before, pivot->data);
     while (p != NULL)
     {
           insertNodeAtEnd(&before, p->data);
           p = p->next;
     } 
     
}
