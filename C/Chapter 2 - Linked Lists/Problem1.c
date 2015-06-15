#include "Problem1.h"

void runProblem1()
{
     node* p = (node*) malloc(sizeof(node));
     p = NULL;
  
     insertNodeAtEnd(&p, 5);
     insertNodeAtBeginning(&p, 10);
     insertNodeAtBeginning(&p, 9);
     insertNodeAtBeginning(&p, 4);
     insertNodeAtBeginning(&p, 2);
     insertNodeAtBeginning(&p, 7);
     insertNodeAtEnd(&p, 12);
     insertNodeAtEnd(&p, 15);
     insertNodeAtEnd(&p, 7);
     insertNodeAtEnd(&p, 5);
    
     printListToConsole(p);
     
     removeDuplicates(p);
     printListToConsole(p);
     free(p);  
} 

void removeDuplicates(node* head)
{
     node* current, *runner;
     current = head;
     
     while (current != NULL)
     {
           runner = current->next;     
           while (runner != NULL)
           {
                 printf("Comparing %d with %d\n", current->data, runner->data);
                 if (current->data == runner->data)
                 {
                     node* aux = runner;
                     deleteNode(&head, aux);
                 }
                 runner = runner->next;
           }
           current = current->next;
     }
     printf("Duplicates have been removed from list.\n");      
}
