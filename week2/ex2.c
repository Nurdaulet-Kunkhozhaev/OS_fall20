#include <stdio.h>
#include <string.h>

int main()
{
   char input_string[100];

   printf("Input a string: ");
   scanf("%s", &input_string);
    
    char output_string[100];
    int i;
   for (i = 0; i < strlen(input_string); i++) {
      output_string[i] = input_string[strlen(input_string) - 1 - i];
   }

   output_string[strlen(input_string)] = '\0';

   printf("%s\n", output_string);

   return 0;
}
