#include <stdio.h>

#define MAX_SIZE 100 

int main() {
    int a[MAX_SIZE], i, j, tmp, n;
    printf("\n\n Pointer: Sort an array using pointer:\n");
    printf("--------------------------------------------\n");

    printf("Input the number of elements to store in the array (max %d): ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("Error: Number of elements exceeds the maximum size of %d.\n", MAX_SIZE);
        return 1; 
    }

    printf("Input %d number of elements in the array:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element - %d: ", i + 1);
        scanf("%d", &a[i]);  
    }

    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }

    printf("\nThe elements in the array after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("Element - %d: %d\n", i + 1, *(a + i));
    }

    return 0; 
}
