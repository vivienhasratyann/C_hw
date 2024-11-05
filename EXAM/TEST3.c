#include <stdio.h>

#define MAX_LEN 10000

void concatenate(char* str1, char* str2){
    int found = 0;
    for (int i=0; i<MAX_LEN; i++){
        if(*(str1+i)=='\0'){
            found = i;
            break;
        }
    }
    *(str1+found) = ' ';
    for(int i=1; i<MAX_LEN; i++){
        if(*(str2+i-1)=='\0'){
            break;
        }
        *(str1+found+i) = *(str2+i-1);
    }
    
}
//  [1, 2, 3, 4, 5]

int main(){

    char str1[MAX_LEN] = "hello";
    char str2[MAX_LEN] = "world";

    concatenate(str1, str2);

    printf("%s", str1);

    return 0;

}