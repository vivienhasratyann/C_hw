#include <stdio.h>

#define TOTAL_CHARS 128  // Considering ASCII characters from 0 to 127

int main() {
    int c;
    int char_count[TOTAL_CHARS];  // Array to store frequency of each character
    int i, j;

    // Initialize the frequency array to zero
    for (i = 0; i < TOTAL_CHARS; i++)
        char_count[i] = 0;

    // Read characters from input until EOF
    while ((c = getchar()) != EOF) {
        if (c >= 0 && c < TOTAL_CHARS)  // Make sure character is within the array bounds
            char_count[c]++;
    }

    // Print the histogram
    printf("\nCharacter Frequency Histogram:\n");
    for (i = 0; i < TOTAL_CHARS; i++) {
        if (char_count[i] > 0) {  // Print only characters that appeared in input
            if (i >= 32 && i <= 126)
                printf("%c: ", i);  // Printable ASCII characters
            else
                printf("%d: ", i);  // Non-printable characters, display as numbers

            // Print frequency as a horizontal bar of '*'
            for (j = 0; j < char_count[i]; j++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
