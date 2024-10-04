#include <stdio.h>
#include <string.h>  

#define MAXCHAR 1000  

void reverse_str(char givstr[]);

int main() {
    char text[MAXCHAR];
    int len;

    while (fgets(text, MAXCHAR, stdin) != NULL) {
        len = strlen(text);
        if (text[len - 1] == '\n')
            text[len - 1] = '\0';
        
        reverse_str(text);
        printf("%s\n", text);
    }

    return 0;
}

void reverse_str(char givstr[]) {
    int i, j;
    char temp;

    for (i = 0, j = strlen(givstr) - 1; i < j; i++, j--) {
        temp = givstr[i];
        givstr[i] = givstr[j];
        givstr[j] = temp;
    }
}
