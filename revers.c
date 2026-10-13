#include <stdio.h>
#include <stdlib.h>

void revers() {
    char c[100];
    printf("Enter the name of the file you want to reverse: \n");
    scanf("%s", c);
    FILE *p = fopen(c, "r");
    if (p == NULL) {
        printf("This file does not exist.\n");
        return ;
    }
    fseek(p, 0, SEEK_END);
    int file_size = ftell(p);
    char w[file_size + 1];
    int i = 0;
    while (file_size > 0) {
        fseek(p, --file_size, SEEK_SET);
        w[i++] = fgetc(p);
    }
    w[i] = '\0';
    fclose(p);
    p = fopen(c, "w");
    fprintf(p, "%s", w);
    fclose(p);
}
