// Horizontal Histogram

#include <stdio.h>

int main() {
    int c;
    int word_length = 0;
    int i, j;
    int word_lengths[20];  // Track word lengths up to 19 characters
    int max_count = 0;     // Maximum frequency of any word length

    // Initialize the array with zeros
    for (i = 0; i < 20; i++)
        word_lengths[i] = 0;

    // Read characters until end-of-file (EOF)
    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            word_length++;
        } else if (word_length > 0) {
            if (word_length < 20)
                word_lengths[word_length]++;
            word_length = 0;
        }
    }

    // Handle the last word if the input ends without space
    if (word_length > 0 && word_length < 20)
        word_lengths[word_length]++;

    // Find the maximum frequency of word lengths
    for (i = 1; i < 20; i++) {
        if (word_lengths[i] > max_count)
            max_count = word_lengths[i];
    }

    // Print the vertical histogram
    for (j = max_count; j > 0; j--) {
        for (i = 1; i < 20; i++) {
            if (word_lengths[i] >= j)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

    // Print the length labels
    for (i = 1; i < 20; i++)
        printf(" %d ", i);

    return 0;
}
