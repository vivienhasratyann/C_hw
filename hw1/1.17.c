#include <stdio.h>

#define MAXCHAR 1000

int get_input_line(char line[], int lim);  

int main() {
    char longline[MAXCHAR];
    int len;
    
    while ((len = get_input_line(longline, MAXCHAR)) > 0) {
        if (len > 80) {
            printf("%s", longline);
        }
    }

    return 0;
}

int get_input_line(char line[], int lim) {
    int i = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n') {
        if (i < lim - 1)  
            line[i] = c;
        ++i;
    }
    
    if (c == '\n') {
        if (i < lim - 1)  
            line[i] = c;
        ++i;
    }
    
    line[i] = '\0';  
    return i;  
}
