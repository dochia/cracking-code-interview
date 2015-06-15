#include <stdio.h>
#include <stdlib.h>

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

char* readStringFromFile(char filename[])
{
     FILE *ifp;
     char *mode = "r";
     long lSize;
     int aux = 0;
     
     ifp = fopen(filename, mode);

     if (ifp == NULL) 
     {
        fprintf(stderr, "Can't open input file \n");
        exit(1);
     }
     else
     {
      fseek (ifp , 0 , SEEK_END);
      lSize = ftell (ifp);
      rewind (ifp);
        
      char* result = (char*) malloc((lSize + 1) * sizeof(char));
      if (result == NULL) 
      {
           fputs ("Memory allocation error", stderr); 
           exit (2);
      }
      aux = fread (result, sizeof(char), lSize, ifp);
      if (aux != lSize) 
      {
             fputs ("Reading from file error", stderr); 
             exit (3);
      }
      
      *(result + lSize) = '\0';  
      fclose(ifp);
      return result;
     }     
}

int strLen(char* str)
{
    int result = 0;
    while (*(str + result) != '\0')
          result++;
    return result;
}

void reverse(char* str)
{
     int i = 0;
     int len = strLen(str);
     printf("%d\n", len);
     char* result = (char*) malloc(sizeof(char) * len);    
     while (*(str+i) != '\0')
     {
           result[len - 1 - i] = str[i];
           i++;
     }
     *(result+i) = '\0';
     printArray(result);
}
void reverseInPlace(char* str)
{
     int i = 0;
     int len = strLen(str);
     char temp;
     while (i < len / 2)
     {
           temp = str[i];
           str[i] = str[len - 1 - i];
           str[len - 1 - i] = temp;
           i++;
     }
     printArray(str);
 }


int main()
{
    char* str = readStringFromFile("data.txt");
    printArray(str);
    
    //reverse(str);
    reverseInPlace(str);
      
    system("pause");
    return 0;
}
