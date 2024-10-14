#include <stdio.h>
#include <string.h>

void reverseString(char *str) {
    int length = strlen(str);  

    printf("Reverse of the string is: ");
    for (int i = length - 1; i >= 0; i--) {
        printf("%c", *(str + i));  
    }
    printf("\n");
}

int main() {
    char str[100];  

    printf("Input a string: ");
    scanf("%s", str);  

    printf("\nPointer : Print a string in reverse order :\n");
    printf("------------------------------------------------\n");
    printf("Input a string : %s\n", str);

    reverseString(str);

    return 0;
}
