#include <stdio.h>  //[0,1,1,2,3,5]

int power(int n, int degree){
    if(degree<=1){
        return n;
    }else{
        return n* power(n, degree-1);
    }
}

int main(){

    int n, deg;
    printf("please input the number :");
    scanf("%d", &n);
    printf("please input the degree :");
    scanf("%d", &deg);

    printf("the value of %d^%d is %d", n, deg, power(n, deg));

}