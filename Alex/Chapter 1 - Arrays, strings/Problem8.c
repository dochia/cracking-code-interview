#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


int strLen(char* str)
{
    int result = 0;
    while (*(str + result) != '\0')
          result++;
    return result;
}

bool isSubstring(char* s1, char* s2)
{
     bool result = false;
     int i = 0;
     int j = 0;
     int s1len = strLen(s1);
     int s2len = strLen(s2);
     bool found = true;
     while (*(s1 + i) != '\0')
     {
           j = 0;
           found = true;
           while (*(s2 + j) != '\0')
           {                 
                 if (*(s1 + i) == *(s2 + j))
                 {
                    j++;
                    //found = found && true;
                 }
                 else
                 {
                     found = false;
                     j = s2len;
                 }
                 i++;
           }
           if (found)
           {
              result = true;
              //i = s1len;
           }
     }
     return result;    
}

void printArray(char* arr)
{
      int i = 0;
      while (*(arr + i) != '\0')
      {
            printf("%c ", arr[i]);
            i++;
      }
      printf("\n");
}

char* doubleString(char* s1)
{
     int len = strLen(s1);
     int newLen = len  * 2 + 1;
     char* s1copy = (char*) malloc(sizeof(char) * newLen);
     // create new string 's1copy' by doubling the content of s1  
     int i = 0;
     for (i = 0; i < 2; i++)
     {
         int j = 0;
         while (*(s1 + j) != '\0')
         {
               *(s1copy + i*len + j) = *(s1 + j);
               j++;
               
         }
     }
     *(s1copy + newLen - 1) = '\0';
     return s1copy; 
}

bool isRotation(char* s1, char* s2)
{
     bool result = false;
     int len = strLen(s1);
     if (len != strLen(s2))
        return false;
     char* s1copy = doubleString(s1);
     //printArray(s1copy);
     int i = 0;
     if (isSubstring(s1copy, s2))
            result = true;
    
     return result;
 }

int main()
{
    printf("%d\n",isSubstring("water", "ter"));  
    printf("%d\n",isSubstring("water", "tea"));
    printf("%d\n",isSubstring("water", "ata"));  
    
    char* a = "alabala";
    char* b = "labalaa";
    printf("isRotation(%s, %s) = %d\n", a, b, isRotation(a, b));
    
    a = "waterbottle";
    b = "terbottlewa2";
    printf("isRotation(%s, %s) = %d\n", a, b, isRotation(a, b));
    
    a = "waterbottle";
    b = "terbottlewe";
    printf("isRotation(%s, %s) = %d\n", a, b, isRotation(a, b));
    
    system("pause");
    return 0;
}
