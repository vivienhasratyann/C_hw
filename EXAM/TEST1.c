#include <stdio.h>

int main(){
    int n;
    printf("Enter the number of the integers");
    scanf("%d", &n);

    int array[n];
    int counted[n];     //  array [1, 1, 2, 1, 3] \\ counted[0, 1, 0, 1, 0]

    for(int i=0; i<n; i++){
        counted[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("input the element number %d\n", i+1);
        scanf("%d", &array[i]);
    }

    for (int i =0; i<n; i++){

        if(counted[i]){
            continue;
        }

        int count = 1;
        for (int j=i+1; j<n; j++){
            if(array[i]==array[j]){
                count++;
                counted[j] = 1;
            }else{
                continue;
            }
            
        }

        printf("The frequency of %d is %d\n", array[i], count);
    }
    
}