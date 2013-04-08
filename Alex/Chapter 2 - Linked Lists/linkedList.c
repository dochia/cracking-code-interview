#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

int insertHead(node** head, int value)
{
    node* newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = value;
    if (*head == NULL)
    {
        *head = newNode;
        (*head)->next = NULL;   
        //free(newNode);   
        return 1;
    }
    else
    {
        //free(newNode);
        return 0;
    }
}

int insertNodeAtBeginning(node** head, int value)
{   
      if ( *head == NULL)
      {
          insertHead(head, value);
      }
      else
      {
          node* newNode = (node*) malloc(sizeof(node));
          newNode->data = value;
          if (newNode == NULL)
          {
             return 0;            
          }
          else
          {
              newNode->next = *head;
              *head = newNode;
              //free(newNode);
              return 2;
          }
      }
} 

int insertNodeAtEnd(node** head, int value)
{
    if (insertHead(head, value) == 1)
    {
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
            node* temp = (node*) malloc(sizeof(node));
            temp = (*head)->next;
            while (temp->next != NULL)
            {
                  temp = temp->next;
            }
            temp->next = newNode;
            //free(temp);
            //free(newNode);
            return 1;
        }
    }
}

int countNodes(node* head)
{
    node *temp = (node*)malloc(sizeof(node));
    temp = head;
    int counter = 1;
    while (temp->next != NULL)
    {
          temp = temp->next;
          counter++;
    }
    free(temp);
    return counter;
}

int insertNodeAtPositionFromBeginning(node** head, int position, int value)
{
    if (position == 0)
    {
        insertHead(head, value);      
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
            node* temp = (node*) malloc(sizeof(node));
            temp = (*head);
            int counter = 1;
            int noNodes = countNodes(*head);
            if ( noNodes < position)
            {
                printf("Position to insert is greater than the lenght of the list.\n");
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
                    printf("Adding new node as the end of list.\n");       
                    //free(newNode);
                    //free(temp); 
                    return 3;
                }
                else
                {
                     newNode->next = temp->next->next;
                     temp->next = newNode;         
                     printf("Adding new node with value %d in position %d in the list.\n", value, position);
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
    node* temp = (node*) malloc(sizeof(node));
    temp = *head;
    if (temp->data == value)
    {
        *head = temp->next;
        free(temp);
        return 1;           
    }
    else
    {
        while (temp->next != NULL && temp->next->data != value)
        {
              temp = temp->next;
        }
        if (temp->next->data == value)
        {
              //temp->next = temp->next->next;
              free(temp->next->next);
              temp->next = NULL;
              return 1;
        }
        else
        {
            printf("Node with value %d was nod found in the list.\n", value);
            return 0;
        }
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
    return 0;
}
