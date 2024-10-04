#include <stdio.h>

void expand(char s1[], char s2[]);

int main() {
    int i;
    int c;
    char s1[1000];
    char s2[1000];

    i = 0;
    while ((c = getchar()) != EOF && c != '\n') {
        s1[i++] = c;
    }
    s1[i] = '\0';  
    expand(s1, s2);  
    printf("%s\n", s2);  

    return 0;
}

void expand(char s1[], char s2[]) {
    int i = 0;  
    int j = 0;  
    char c;

    while ((c = s1[i++]) != '\0') {
        if (c == '-') {
            if (i == 1 || s1[i] == '\0') {
                s2[j++] = '-';  
            } else {
                char start = s1[i - 2];  
                char end = s1[i];        
                if (start < end) {
                    for (char k = start + 1; k <= end; k++) {
                        s2[j++] = k;  
                    }
                } else {
                    s2[j++] = '-';  
                }
            }
        } else {
            s2[j++] = c;  
        }
    }
    s2[j] = '\0'; 
}