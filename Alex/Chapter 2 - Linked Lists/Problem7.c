#include "Problem7.h"

void runProblem7()
{
     node* p = (node*)malloc(sizeof(node));
     p = NULL;
     
     insertNodeAtEnd(&p, 1);
     insertNodeAtEnd(&p, 5);
     insertNodeAtEnd(&p, 7);
     insertNodeAtEnd(&p, 7);
     insertNodeAtEnd(&p, 6);
     insertNodeAtEnd(&p, 1);
     
     printf("%d \n", isListPalindromeIterative(p));
     
     printf("%d \n", isListPalindromeRecursive(p));
     free(p);
}

bool isListPalindromeIterative(node* head)
{
     bool result = true;
     node* p = (node*)malloc(sizeof(node));
     p = NULL;
     node* q = head;
     while (q != NULL)
     {
           insertNodeAtBeginning(&p, q->data);
           q = q->next;
     }
     printListToConsole(p);
     q = head;
     while (p != NULL && q != NULL)
     {
           if (p->data != q->data)
           {
               result = false;
               break;
           }
           p = p->next;
           q = q->next;
     }
     return result;
}

resultPalindrome recursePalindromeHelper(node* head, int len)
{
    if (head == NULL && len == 0)
    {
             resultPalindrome tempRes = {NULL, true};
             return tempRes;
    }             
    else 
    {
         if (len == 1)
         {
                 resultPalindrome tempRes = {head->next, true};
                 return tempRes;
         }
         else if (len == 2)
              {
                      resultPalindrome tempRes = {head->next->next, head->data == head->next->data};
                      return tempRes;
              }
    }
    resultPalindrome tempRes = recursePalindromeHelper(head->next, len-2);
    if (!(tempRes.res) || tempRes.next == NULL)
    {
        return tempRes;
    } 
    else
    {
        tempRes.res = head->data == tempRes.next->data;
        tempRes.next = tempRes.next->next;
        return tempRes;
    }
}

bool isListPalindromeRecursive(node* head)
{
     resultPalindrome result = recursePalindromeHelper(head, countNodes(head));
     return result.res;
}
