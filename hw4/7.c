#include <stdio.h>

int main() {
    int n;
    printf("Input the number of elements to store in the array: ");
    scanf("%d", &n);

    int arr[n]; // Variable-length array declaration (C99 or later)
    int *ptr = arr; // Pointer to the first element of the array

    printf("Input %d number of elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i);
        scanf("%d", ptr + i); // Input elements using pointer arithmetic
    }

    printf("\nThe elements you entered are:\n");
    for (int i = 0; i < n; i++) {
        printf("element - %d : %d\n", i, *(ptr + i)); // Print elements using pointer dereferencing
    }

    return 0;
}
