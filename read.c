#include <stdio.h>
#include <stdlib.h>

void read() 
{
    char c[100];
    printf("Enter the name of the file you want to read: \n");
    scanf("%s", c);
    printf("------ The content of this file is -------\n");
    FILE *p = fopen(c, "r");
    if (p == NULL)
    {
        printf("This file does not exist.\n");
        return;
    }
    int x;
    while ((x = fgetc(p)) != EOF) 
    {
        printf("%c", x);
    }
    fclose(p);
    printf("\n-----------------------------------------\n");
    printf("Press any key to continue...");
    while (getchar() != '\n'); 
    getchar(); 
    printf("\n"); 
}