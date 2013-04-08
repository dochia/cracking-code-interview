#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int strLen(char* str)
{
    int i = 0;
    while (*(str + i) != '\0') 
    {
          i++;
    }
    return i;
}


void printArrayToConsole(char* array) 
{
      int i = 0; 
      while (*(array + i) != '\0')
      {
            printf("%c ", array[i]);
            i++;
      }
      printf("\n");
}

void interchange(char* array, int i, int j)
{
     char temp;
     temp = array[i];
     array[i] = array[j];
     array[j] = temp;
}

char* bubbleSort(char* array) 
{
     int arraySize = strLen(array); 
     int i, j;
     for (i = 0; i < arraySize - 1  ; i++)
     {
          for (j = 0; j < arraySize - 1 - i; j++ )
          {
              if (array[j] > array[j+1])
              {
                    interchange(array, j+1, j);
              }
          }
     }
     return array;
}

char* removeDuplicateFromString(char* a) 
{
      char* start = a++; // is start an array, an iterator, what is it?
      char* next = start++;
      while (*next != '\0')
      {
            if (*start == *next)
            {
               next++;
            }
            else
            {
                start++;
                *start = *next;
                next++;
            }   
            
      }
      start++;
      *start = '\0';
      return a;
}

int main()
{
    char* str = (char*) malloc(sizeof(char) * 9);
    strcpy(str, "aaabbaccb");
    printArrayToConsole(str);
    
    str = bubbleSort(str);
    printArrayToConsole(str);
    
    char* result = removeDuplicateFromString(str);
    printArrayToConsole(result);
    
    free(str);
    free(result);
    system("pause");
    return 0;
}
