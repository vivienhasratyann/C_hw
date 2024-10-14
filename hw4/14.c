#include <stdio.h>

void sortArray(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}

int main() {
    int n;

    printf("Input the number of elements to store in the array: ");
    scanf("%d", &n);

    int arr[n];  

    printf("Input %d number of elements in the array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("element - %d : ", i + 1);
        scanf("%d", arr + i);  
    }

    sortArray(arr, n);

    printf("\nThe elements in the array after sorting:\n");
    for (int i = 0; i < n; i++) {
        printf("element - %d : %d\n", i + 1, *(arr + i));  
    }

    return 0;
}
