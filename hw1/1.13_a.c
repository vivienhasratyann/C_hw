// Horizontal Histogram

#include <stdio.h>

int main() {
    int c;
    int word_length = 0;
    int i, j;
    int word_lengths[20];  
    int max_count = 0;     

    for (i = 0; i < 20; i++)
        word_lengths[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n' && c != '\t') {
            word_length++;
        } else if (word_length > 0) {
            if (word_length < 20)
                word_lengths[word_length]++;
            word_length = 0;
        }
    }

    if (word_length > 0 && word_length < 20)
        word_lengths[word_length]++;

    for (i = 1; i < 20; i++) {
        if (word_lengths[i] > max_count)
            max_count = word_lengths[i];
    }

    for (j = max_count; j > 0; j--) {
        for (i = 1; i < 20; i++) {
            if (word_lengths[i] >= j)
                printf(" * ");
            else
                printf("   ");
        }
        printf("\n");
    }

    for (i = 1; i < 20; i++)
        printf(" %d ", i);

    return 0;
}
