#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int calculate(const char* expression) {
    int result = 0;
    int temp = 0;
    char lastOp = '+';

    for (; *expression; ++expression) {
        if (*expression >= '0' && *expression <= '9') {
            temp = (temp * 10) + (*expression - '0');
        }
        else if (*expression == '+' || *expression == '-') {
            if (lastOp == '+') result += temp;
            else if (lastOp == '-') result -= temp;

            temp = 0;
            lastOp = *expression;
        }
        else if (*expression == '*' || *expression == '/') {
            char op = *expression;
            int num = 0;
            ++expression;

            while (*expression >= '0' && *expression <= '9') {
                num = (num * 10) + (*expression - '0');
                ++expression;
            }
            --expression;

            if (op == '*') temp *= num;
            else temp /= num;
        }
    }

    if (lastOp == '+') result += temp;
    else if (lastOp == '-') result -= temp;

    return result;
}

bool isValidExpression(const char* expression) {
    if (strpbrk(expression, "+-*/") == expression || strpbrk(expression + strlen(expression) - 1, "+-*/"))
        return false;

    for (; *expression; ++expression) {
        if (!(*expression >= '0' && *expression <= '9') && !strchr("+-*/", *expression))
            return false;

        if (strchr("+-*/", *expression) && strchr("+-*/", *(expression + 1)))
            return false; 
    }

    return true; 
}

int main() {
    char expression[256];
    printf("입력식: ");
    scanf("%255s", expression);

    if (!isValidExpression(expression)) {
        printf("입력식이 잘못되었습니다.\n");
        return 1;
    }

    int result = calculate(expression);
    printf("결과: %d\n", result);
    return 0;
}
