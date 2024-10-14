#include <stdio.h>

int main() {
    char alphabets[26];  
    char *ptr = alphabets;  

    for (int i = 0; i < 26; i++) {
        *(ptr + i) = 'A' + i;
    }

    printf("The Alphabets are:\n");
    for (int i = 0; i < 26; i++) {
        printf("%c  ", *(ptr + i));  
    }
    printf("\n");

    return 0;
}
