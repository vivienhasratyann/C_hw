#include <stdio.h>

struct Time {
    int h;
    int min;
    int sec;
};

struct Time addtimes(struct Time t1, struct Time t2){
    struct Time result;

    result.sec = t1.sec + t2.sec;
    result.min = result.sec / 60;
    result.sec %= 60;

    result.min += t1.min + t2.min;
    result.h = result.min / 60;
    result.min %= 60;

    result.h += t1.h + t2.h;
    result.h %= 24;

    return result;
}

struct Time inputTime() {
    struct Time t;
    printf("Enter time (h min sec): ");
    scanf("%d %d %d", &t.h, &t.min, &t.sec);
    return t;
}

void displayTime(struct Time t){
    printf("%02d:%02d:%02d\n", t.h, t.min, t.sec); // If the integer has less than 2 digits, it will be padded with leading zeros.
}

int main() {
    struct Time t1, t2, result;

    printf("Input first time: \n");
    t1 = inputTime();

    printf("Input second time: \n");
    t2 = inputTime();

    result = addtimes(t1, t2);

    printf("Result time: \n");
    displayTime(result);


    return 0;
}