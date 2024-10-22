#ifndef _CALC_H_
#define _CALC_H_

/**
 * @file calc.h
 * @brief Header file for a Reverse Polish Notation calculator.
 */

#define NUMBER '0'  // signal that a number was found

/**
 * @brief Get the next character from input or a pushed-back character.
 *
 * @return The next character from input or a pushed-back character.
 */
int getch(void);

/**
 * @brief Push a character back to the input buffer.
 *
 * @param c The character to be pushed back.
 */
void ungetch(int c);

/**
 * @brief Push a double value onto the stack.
 *
 * @param f The double value to be pushed onto the stack.
 */
void push(double f);

/**
 * @brief Pop and return the top value from the stack.
 *
 * @return The top value from the stack.
 */
double pop(void);

/**
 * @brief Get the next operator or numeric operand.
 *
 * This function reads characters from input and identifies whether it's a
 * number or an operator.
 *
 * @param s The character array where the operator or operand is stored.
 * @return If the input is a number, it returns '0' (NUMBER); otherwise, it returns
 * the read character.
 */
int getop(char s[]);

#endif // _CALC_H_