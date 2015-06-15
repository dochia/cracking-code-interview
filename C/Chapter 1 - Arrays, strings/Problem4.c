#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int computeAppearances(char* str, char a)
{
    int result = 0;
    int i = 0;
    while (*(str + i) != '\0')
    {
          if (str[i] == a)
             result++;
          i++;
    }
    return result;
}

void printArray(char* arr)
{
      int i = 0;
      while (*(arr + i) != '\0')
      {
            printf("%c", arr[i]);
            i++;
      }
      printf("\n");
}


int strLen(char* str)
{
    int result = 0;
    while (*(str + result) != '\0')
          result++;
    return result;
}

char* addSpaces(char* str)
{
      int addLen = computeAppearances(str, ' ');
      int strL = strLen(str);
      int newLen = addLen * 2 + strL;
      char* result = (char*) malloc(sizeof(char) * newLen);
      int i = 0;
      while (*(str + i) != '\0')
      {
            result[i] = str[i];
            i++;
      }
      for (i = strL; i < newLen; i++)
          *(result + i) = ' ';
      *(result + newLen) = '\0';
      return result; 
}

char* replace(char* str, char replacing, char* with)
{
      int strL = strLen(str);
      char* result = addSpaces(str);
      int newLen = strLen(result);
      int withLen = strLen(with);
      int i = 0;
      
      while ((strL - 1)!= 0)
      {
            if (str[strL - 1] != replacing)
            {
                result[newLen - 1] = str[strL - 1];
                newLen--;
                strL--;
            }
            else
            {
                for (i = withLen - 1; i >= 0 ; i--)
                    result[--newLen] = with[i];
                strL--;  
            }  
      }
      return result;
}


int main()
{
    char* str = "ala bala portocala";
    char* a = replace(str, ' ', "%20");
    printArray(a);
    free(a);
    free(str);
    system("pause");
    return 0;
}
