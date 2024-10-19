#include <stdio.h>
#include <string.h>

#define MAX_NAMES 100  
#define MAX_LENGTH 50  

void duplicates(char names[][MAX_LENGTH], int n) {
    printf("\nDuplicate names:\n");
    int foundDuplicate = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(names[i], names[j]) == 0) {
                printf("%s\n", names[i]);
                foundDuplicate = 1;
                break; 
            }
        }
    }

    if (!duplicates) {
        printf("No duplicate names found.\n");
    }
}

int main() {
    char names[MAX_NAMES][MAX_LENGTH];
    int n;

    printf("Enter the number of names: ");
    scanf("%d", &n);

    printf("Enter %d names:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    duplicates(names, n);

    return 0;
}
