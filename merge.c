#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>
void mergee(FILE *p,FILE* p3)
{
    fputc(' ',p3);
    char x[100];
    while(fgets(x,100,p) != NULL)
    {
        fputs(x,p3);
    }
}
bool verifee(char t[],char g[])
{
    if(strlen(t) != strlen(g))return false;
    for(int i =0;i<strlen(t);i++)
    {
        if(t[i] != g[i])return 0;
    }    
    return 1;
}
void merge()
{
    char c[100];
    printf("Enter the name of the file you want to merge the two files into :  \n");
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
            } while ((verifee(q,"yes") != true && verifee(q,"no")!=true));
            if(verifee(q,"yes")==true)p=fopen(c,"a+");
            else return;
        }
    } while (p==NULL);
    FILE *p2;
    FILE *p3;
    printf("Entre the name of file 1 : \n");
    scanf("%s",c);
    p2 = fopen(c,"r");
    if(p2==NULL)
    {
        printf("This file does not exist : \n");
        return;
    }
    mergee(p2,p);
    fclose(p2);
    printf("Entre the name of file 2 \n");
    scanf("%s",c);
    p3 = fopen(c,"r");
    if(p3==NULL)
    {
        printf("This file does not exist : \n");
        return;
    }
    mergee(p3,p);
    fclose(p3);
    fclose(p);
}   