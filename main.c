//MY_NAME : Mokhtar Mammeri
//Group 2
//to execute this file use : gcc *.c    and ./a.out
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "my_functions.h"

void show_menu() { 
    char c[]="┌─────┬─────────────────────────────────────────────────────────────────────────┐\n";
    char s[]="├─────┼─────────────────────────────────────────────────────────────────────────┤\n";
    char h[]="└─────┴─────────────────────────────────────────────────────────────────────────┘\n";
    const char *colors[] = {" Make a file ", " Write in file ", " Read from a file ", " Count the number of lines in a file ", " Find the longest line in a file ", " Reverse file content ", " Merge the contents of two files ", " Find the number of times a word appears ", " Replace one word with another ", " Copy Contents of One File to Another ", " Exit "};
    printf("\n============================ File Handling Toolbox ===============================\n");
    printf("%s",c);
    for(int i = 0; i < 11; i++) {
        if(i != 10) printf("│  %d  │", i);
        else printf("│  %d │", i);
        printf("%s", colors[i]);
        for(int j = 0; j < 73 - strlen(colors[i]); j++) printf(" ");
        printf("│\n");
        if(i != 10) printf("%s", s);
        else printf("%s", h);
    }
}

int main() {   
    char input[10];
    int x;
    while (1) {
        show_menu();
        printf("Choose any tool you want to use: ");
        scanf("%s", input);  
        if (sscanf(input, "%d", &x) != 1) {
            printf("Invalid choice. Please enter a valid number.\n");
            continue; 
        }
        switch (x) {
            case 0:
                creat_file();
                break;
            case 1:
                write();    
                break;
            case 2:
                read();
                break;
            case 3:
                count();
                break; 
            case 4:
                max();
                break;
            case 5:
                revers();
                break;
            case 6:
                merge();
                break; 
            case 7:
                appears();
                break;       
            case 8:
                replac();
                break;  
            case 9:
                fcopy();
                break;
            case 10:
                return 0;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;                              
        }
    }

    return 0;
}
