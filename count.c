#include<stdio.h>
#include<stdlib.h>
void count()
{
    char c[100];
    printf("Entre the name of file you Count the number of lines into : \n");
    scanf("%s",c);
    FILE *p;
    p = fopen(c,"r");
    if(p == NULL)
    {
        printf("This file does not exist \n");
        return;
    }
   int i=1,a = fgetc(p);
    while(a != EOF)
    {
        if(a=='\n')i++;
        a = fgetc(p);
    }
    printf("The number of line is %d\n",i-1);
    fclose(p);
}