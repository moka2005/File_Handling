#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
bool verif(char t[],char g[])
{
    if(strlen(t) != strlen(g))return false;
    for(int i =0;i<strlen(t);i++)
    {
        if(t[i] != g[i])return 0;
    }    
    return 1;
}
void write()
{
    char c[100];
    printf("Entre the name of file you want write it : \n");
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
            } while ((verif(q,"yes") != true && verif(q,"no")!=true));
            if(verif(q,"yes")==true)p=fopen(c,"a+");
            else return;
        }
    } while (p==NULL);
    printf("Entre what do you want to write in this file \n");
    printf("** Enter stopstop to stop the writing ** \n");
    scanf(" %[^\n]",c);
    while (verif(c,"stopstop")==0)
    {
        fprintf(p,"%s\n",c);
        scanf(" %[^\n]",c);
    }
    fclose(p);
}