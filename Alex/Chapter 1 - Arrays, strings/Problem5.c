#include <stdlib.h>
#include <stdio.h>

int strLen(char* str)
{
    int result = 0;
    while (*(str + result) != '\0')
          result++;
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

int countCompression(char* str)
{
    int i = 0;
    int counter = 0;
    int substringlen = 0;
    char temp = str[i];
    while (*(str + i) != '\0')
    {
            counter++;     
            substringlen = 0;
            while (temp == str[i])
            {
                  substringlen++;
                  i++;
            }
            char* aux = (char*) malloc(sizeof(char)*10);
            sprintf(aux, "%d", substringlen);
            printf("%s - lungime %d\n", aux, strLen(aux));
            counter += strLen(aux);  
            //printf("temp = %c de %d ori \n", temp, substrlen);
            temp = str[i];
    }
    return counter;
}

char* executeCompression(char* str)
{
      int length = countCompression(str);
      char* result = (char*) malloc(sizeof(char) * length);
      int i = 0;
      int j = 0;
      int k = 0;
      char temp = str[i];
      int substrlen = 0;
      while (*(str + i) != '\0')
      {
            substrlen = 0;
            while (temp == str[i])
            {
                  substrlen++;
                  i++;
            }
            char* aux = (char*) malloc(sizeof(char)*10);
            sprintf(aux, "%d", substrlen); 
            result[j++] = temp;
            k = 0;
            while (*(aux + k) != '\0')
            {
                  result[j++] = aux[k];
                  k++;
            }
            //printf("temp = %c de %d ori \n", temp, substrlen);
            temp = str[i];
      }
      result[j] = '\0';
      if (j < i)
         return result;
      else
         return str;
}

int main()
{
    char* str = "aabbccccccccddabc";
    printArray(executeCompression(str));
    printf("%d \n ", countCompression(str));
    //printArray(executeCompression("aabbcccccddabc"));
    //printArray(executeCompression("aabbcccccdd"));
    system("pause");
    return 0;
}
