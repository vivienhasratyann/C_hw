#include <stdio.h>
#define SIZE 10

int countfreq(int arr[SIZE], int size){
    int count = 0;
    printf("Integers and their frequencies\n");
    for (int i = 0; i < size; i++){
        if (arr[i] == -1){
            continue;
        }

        int count = 1;
        for (int j = i + 1; j < size; j++){
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -1;
            }
        }

        if(count > 1){
            printf("Integer %d appears %d times\n", arr[i], count);
        }
    } 

    if (!count){
        printf("No duplicates");
    } 
}

int main(){
    int numbers[SIZE];
    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &numbers[i]);
    }

    countfreq(numbers, n);

    return 0;



}