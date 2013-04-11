#include "linkedList.h"

int insertNodeAtBeginning(node** head, int value)
{   
      node* newNode = (node*) malloc(sizeof(node));
      if (newNode == NULL)
      {
          return 0;
      }
      else
      {
          newNode->data = value;
          newNode->next = NULL;
          if (*head == NULL)
          {
               *head = newNode;
               printf("ADD: Node with value %d has been added as the head of the empty list.\n", value);
               return 1;
          }
          else
          {
              newNode->next = *head;
              *head = newNode;
              printf("ADD: Node with value %d has been added as the head of the list.\n", value);
              return 2;
          }
      }
} 

int insertNodeAtEnd(node** head, int value)
{
    node* newNode = (node*) malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    if (*head == NULL && newNode != NULL)
    {
        *head = newNode;
        printf("ADD: Node with value %d has been added at the end of the empty list.\n", value);
        return 1;      
    }
    else
    {
        if (newNode == NULL)
        {
            return 0;
        }
        else
        {
            node* temp = *head;
            while (temp->next != NULL)
            {
                  temp = temp->next;
            }
            temp->next = newNode;
            printf("ADD: Node with value %d has been added at the end of the list.\n", value);
            return 1;
        }
    }
}

int countNodes(node* head)
{
    node *temp;
    temp = head;
    int counter = 1;
    while (temp->next != NULL)
    {
          temp = temp->next;
          counter++;
    }
    return counter;
}

int insertNodeAtPositionFromBeginning(node** head, int position, int value)
{
    if (position == 0)
    {
        insertNodeAtBeginning(head, value);
        return 1;    
    }
    else
    {
        node* newNode = (node*) malloc(sizeof(node));
        newNode->data = value;
        newNode->next = NULL;
        if (newNode == NULL)
        {
            return 0;
        }
        else
        {
            node* temp = (*head);
            int counter = 1;
            int noNodes = countNodes(*head);
            if ( noNodes < position)
            {
                printf("ADD ERROR: Position to insert is greater than the lenght of the list.\n");
                return 0;
            }
            else
            {
                while (temp->next != NULL && counter != position)
                {
                      temp = temp->next;
                      counter++;
                }
                if (temp->next == NULL)
                {
                    temp->next = newNode;  
                    printf("ADD: Node with value has been added at the end of the list.\n", value);       
                    //free(newNode);
                    //free(temp); 
                    return 3;
                }
                else
                {
                     newNode->next = temp->next->next;
                     temp->next = newNode;         
                     printf("ADD: Adding new node with value %d in position %d in the list.\n", value, position);
                     //free(temp);
                     //free(newNode);
                     return 4;
                }   
            }
        }
    }
}

int deleteNodeWithValue(node** head, int value)
{
    node *temp, *prev;
    temp = *head;
    while (temp != NULL)
    {
          if (temp->data == value)
          {
              if (temp == *head)
              {
                 *head = temp->next;
                 printf("DELETE: Deleting node with value %d found in the head of the list.\n", value);
                 free(temp);
                 return 1;
              }
              else
              {
                  printf("DELETE: Deleting node with value %d found somewhere in the list.\n", value);
                  prev->next = temp->next;
                  free(temp);
                  return 1;
              }
          }
          else
          {
              prev = temp;
              temp = temp->next;
          }
    }
    if (temp == NULL)
    {
       printf("DELETE ERROR: The node with value %d was not found in the list.\n", value);
       return 0;     
    }
}

bool isListEmpty(node* head)
{
     return (head == NULL);
}

int deleteNode(node** head, node* element)
{
    node* temp = *head;
    if (temp == element)
    {
             *head = element->next;
             printf("DELETE: Deleting the node %d which is the head of the list.\n", element->data);
             free(element);
             return 1;
    }
    else
    { 
        while (temp->next != element && temp->next != NULL)
        {
              temp = temp->next;
        }
        if (temp->next == NULL)
        {
               printf("DELETE: Deleting the node with value %d at the end of the list.\n", element->data);
               return 2;
        }
        else
        {
               temp->next = element->next;
               printf("DELETE: Deleting the node with value %d found in the list.\n", element->data);
               return 3;
        }
        
    }
}

int insertNodeAfterNode(node* element, int value)
{
    node* p = (node*) malloc(sizeof(node));
    p->data = value;
    p->next = NULL;
    if (element->next == NULL)
    {
        element->next = p;
    }
    else
    {
        p->next = element->next; 
        element->next = p;
    }
}

int printListToConsole(node* head)
{
    node* elem = (node*)malloc(sizeof(node));
    elem = head;
    while (elem != NULL)
    {
          printf("%d ", elem->data);
          elem = elem->next;
    }
    free(elem);
    printf("\n");
    //system("pause");
    return 1;
}
