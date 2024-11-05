#include <stdio.h>
#include <string.h>


int countVowels(char str[], int length){

    if (length == 0) {
        return 0;
    }
    
    int count = ( str[length-1]=='a'|| str[length-1]=='e' 
    || str[length-1]=='y' || str[length-1]=='u'
     ||str[length-1]=='o' || str[length-1]=='i') ? 1 : 0;
     
    return count + countVowels(str, length-1);
}

int main(){
    char str;

    printf("Enter your string: ");
    scanf("%c", &str);

    int length = strlen(&str);
    
    printf("Number of vowels: %d\n", countVowels(&str, length));

    return 0;
}