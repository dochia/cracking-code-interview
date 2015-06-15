#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
      free(ifp);
      return result;
     }
     
}

bool hasUniqueCharacters(char* str)
{
     bool result = true;
     int i = 0;
     while (*(str + i) != '\0')
     {
           int j = i + 1;
           while (*(str + j) != '\0')
           {
                 if (str[i] == str[j])
                 {
                     result = false;
                 }                   
                 j++;      
           }     
           i++;
     }
     return result;
}


bool toLowerCase(char* str)
{
     bool result = true;
     int i = 0;
     while (*(str + i) != '\0')
     {
           if ( (str[i] >= 97 && str[i] <= 122) || (str[i] >= 65 && str[i] <=90))
           {
                if ((str[i] >= 65) && (str[i] <=90))
                         str[i] += 32; 
           }
           else
                 result = false;
           i++;
     }
     return result;             
}

bool hasUniqueCharacters_ASCII(char* str)
{
     bool result = true;
     int i = 0;
     if (toLowerCase(str))
     {
         int* alphabet = (int*) malloc(sizeof(int) * 26);
         for (i = 0; i < 26; i++)
         {
             alphabet[i] = 0;
         }
         i = 0;
         
         while (*(str + i) != '\0')
         {
              alphabet[str[i]-97]++;
              i++;
         }
         for (i = 0; i < 26; i++)
             if (alphabet[i] > 1)
             {
                result = false;
                return result;
             }
         free(alphabet);
     }
     return result;
}    

int main()
{
      char* str = readStringFromFile("data.txt");
      printArray(str);
      printf("Using 2 loops\n");
      printf("%d\n", hasUniqueCharacters(str));
      printf("Using ASCII \n");
      printf("%d\n", hasUniqueCharacters_ASCII(str));
      free((void*)str);
      system("pause");
      return 0;
}
