#include <stdio.h>
#include <stdlib.h>
void max() 
{
    char c[100];
    printf("Enter the name of the file you want to count the line that have max number of letters :.\n");
    scanf("%s", c);
    FILE *p;
    p = fopen(c, "r");
    if (p == NULL) {
        printf("This file does not exist.\n");
        return;
    }
    int x, i = 1, max = 0, l = 1, m = 0;
    while ((x = fgetc(p)) != EOF) {
        m++;
        if (x == '\n') {
            if (max < m - 1) {
                l = i;
                max = m - 1;
            }
            m = 0;
            i++;
        }
    }
    if (max < m - 1)
    {
        l = i;
        max = m - 1;
    }
    fclose(p);
    if(l==0)printf("The file is null");
    else printf("The longest line is line number %d\n", l);
}
