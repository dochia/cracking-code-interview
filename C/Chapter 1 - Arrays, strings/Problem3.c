#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strLen(char* str)
{
    int result = 0;
    while (*(str + result) != '\0')
          result++;
    return result;
}

bool containsChar(char* arr, char a)
{
     bool found = false;
     int i = 0;
     while (*(arr + i) != '\0')
     {
           if (arr[i] == a)
           {
              found = true;
           }
           i++;
     }
     return found;
} 

bool isPermutation(char* a, char* b)
{
     int lenA = strLen(a);
     int lenB = strLen(b);
     int i = 0; 
     bool isPerm = true;
     if (lenA != lenB)//|| siruri cu elemente unice
        return false;
     else
     {
           while (i < lenA && isPerm)
           {
                 if (containsChar(b, a[i]))
                     isPerm = true;
                 else
                     isPerm = false;
                 i++;
           }   
     }
     return isPerm;   
}

int main()
{
    char* a = "aabc";
    char* b = "abbc";
    printf("%d\n", isPermutation(a,b));
    system("pause");
    return 0;
}
