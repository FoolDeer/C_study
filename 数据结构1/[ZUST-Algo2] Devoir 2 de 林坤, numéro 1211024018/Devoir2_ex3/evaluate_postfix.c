#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 计算后缀表达式的值
double evaluate_postfix(char* expression) {
    // 定义操作数栈
    double stack[100] = {0};
    int stack_top = -1;
    // 使用空格分隔后缀表达式
    char* token = strtok(expression, " ");
    while (token != NULL) {
        if (isdigit(token[0])) { // 如果是数字，则将其转换为 double 类型并压入栈中
            stack_top++;
            stack[stack_top] = atof(token);
        } else if (isalpha(token[0])) { // 如果是字母，则将其当作变量处理
            printf("Enter the value of %c: ", token[0]);
            double value;
            scanf("%lf", &value);
            stack_top++;
            stack[stack_top] = value;
        } else { // 如果是操作符，则从栈中弹出两个操作数，并进行计算
            double right_operand = stack[stack_top];
            stack_top--;
            double left_operand = stack[stack_top];
            stack_top--;
            double result = 0;
            if (token[0] == '+') {
                result = left_operand + right_operand;
            } else if (token[0] == '-') {
                result = left_operand - right_operand;
            } else if (token[0] == '*') {
                result = left_operand * right_operand;
            } else if (token[0] == '/') {
                result = left_operand / right_operand;
            } else if (token[0] == '^') {
                result = pow(left_operand, right_operand);
            }
            stack_top++;
            stack[stack_top] = result;
        }
        token = strtok(NULL, " ");
    }
    return stack[stack_top];
}