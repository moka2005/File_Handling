#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <stdbool.h>
bool vrif(char t[],char g[])
{
    if (strlen(t) != strlen(g)) return 0;
    for(int i =0;i<strlen(t);i++)
    {
        if(t[i] != g[i])return 0;
    }    
    return 1;
}
void appears()
{
    char c[100];
    char w[100];
    int x = 0 ;
    printf("Entre the name of file that you want looking for it \n");
    scanf("%s",c);
    FILE *p;
    p = fopen(c,"r");
    if(p == NULL)
    {
        printf("This file does not exist \n");
        return;
    }
    printf("Entre the word that you want looking it : \n");
    scanf("%s",c);
    while (fscanf(p,"%s",w) ==1)
    {
        if(vrif(c,w))x++;
    }
    fclose(p);
    printf("The word \"%s\" is repeated %d times \n", c, x);
}    