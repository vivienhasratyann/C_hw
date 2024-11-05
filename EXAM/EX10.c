#include <stdio.h>

int sum(int n){
    if(n<10){
        return n;
    }else{
        return n%10+sum(n/10);
    }
}


int main(){

    int n;
    printf("please input the number :");
    scanf("%d", &n);
    printf("the sum of the numbers is %d", sum(n));
}