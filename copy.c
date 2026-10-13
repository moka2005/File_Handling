#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
void cop(FILE *p,FILE* p3)
{
    char x[100];
    fputc(' ',p3);
    while(fgets(x,100,p) != NULL)
    {
        fputs(x,p3);
        
    }
}
bool surch(char t[],char g[])
{
    if(strlen(t) != strlen(g))return false;
    for(int i =0;i<strlen(t);i++)
    {
        if(t[i] != g[i])return 0;
    }    
    return 1;
}
void fcopy()
{
    char c[100];
    printf("Enter the name of the file you want to copy the informaition in him  :  \n");
    scanf("%s",c);
    FILE *p;
    p = fopen(c,"r+");
    if(p!=NULL)fseek(p,0,SEEK_END);
    char q[100];
    do
    {
        if(p==NULL)
        {
            do
            {
                printf("There is no file with this name . do you want creat it ? yes or no ? \n");
                scanf("%s",q);
            } while ((surch(q,"yes") != true && surch(q,"no")!=true));
            if(surch(q,"yes")==true)p=fopen(c,"a+");
            else return;
        }
    } while (p==NULL);
    FILE *p2;
    printf("Entre the name of file that you want copy the information from him : \n");
    scanf("%s",c);
    p2 = fopen(c,"r");
    if(p2==NULL)
    {
        printf("This file does not exist : \n");
        return;
    }
    cop(p2,p);
    fclose(p2);
    fclose(p);
}  