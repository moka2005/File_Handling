#include<stdio.h>
#include<stdlib.h>
void creat_file()
{
    char c[100];
    printf("Entre the name of file you want to creat : \n");
    scanf("%s",c);
    FILE *p;
    p = fopen(c,"w");
    if(p==NULL)
    {
        printf("This file does not exist \n");
        return;
    }
    fclose(p);
}    