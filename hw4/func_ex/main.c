#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

#define MAXOP 100   // max size of operand or operator

// reverse Polish (postfix) calculator
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0)
                push(pop() / op2);
            else
                printf("error: zero division\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0) {
                double op1 = pop();
                push(op1 - (int)(op1 / op2) * op2);
            }
            else
                printf("error: zero division\n");
            break;
        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
