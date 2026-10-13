#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
bool verife(char t[],char g[])
{
    if(strlen(t) != strlen(g))return false;
    for(int i =0;i<strlen(t);i++)
    {
        if(t[i] != g[i])return 0;
    }    
    return 1;
}
void replac()
{
    char c[100];
    char w[1000];
    char k[100];
    printf("Entre the name of file that you want changed \n");
    scanf("%s",c);
    FILE *p;
    p = fopen(c,"r+");
    if(p == NULL)
    {
        printf("This file does not exist \n");
        return ;
    }
    int  j,i =0;
    while ((j = getc(p)) !=EOF)
    {
        w[i] = j;
        i++;
    }
    fclose(p);
    w[i] = ' ';
    w[i+1]='\0';
    p = fopen(c,"w");
    j =-1;
    char v[100];
    printf("Entre the word you want change it \n");
    scanf("%s",v);
    printf("Entre the word that rplace of the last word \n");
    scanf("%s",c);
    for(int i=0;i<strlen(w);i++)
    {
        j++;
        if(w[i] == '\n')
        {
            k[j] = '\0';
            if(verife(v,k)==true)fprintf(p,"%s ",c);
            else fprintf(p,"%s ",k);
            fprintf(p,"%c",w[i]);
            j=-1;
        }
        else
        {
            if(w[i] != ' ')k[j] = w[i];
            else
            {
                k[j] = '\0';
                if(verife(v,k)==true)fprintf(p,"%s ",c);
                else fprintf(p,"%s ",k);
                j=-1;
            }
        }
    }
    fclose(p);
}