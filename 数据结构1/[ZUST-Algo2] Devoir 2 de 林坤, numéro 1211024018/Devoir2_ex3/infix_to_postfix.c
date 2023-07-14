#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int precedence(char operator) {
    // 定义操作符的优先级
    if (operator == '+' || operator == '-') {
        return 1;
    } else if (operator == '*' || operator == '/') {
        return 2;
    } else if (operator == '^') {
        return 3;
    } else {
        return 0;
    }
}

char* infix_to_postfix(char* expression) {
    char* postfix = (char*)malloc(strlen(expression) * sizeof(char)); // 分配存储后缀表达式的空间
    char stack[100] = ""; // 定义操作符栈
    int stack_top = -1;
    char* token = strtok(expression, " "); // 使用空格分隔中缀表达式
    while (token != NULL) {
        if (isdigit(token[0]) || isalpha(token[0])) { // 如果是数字或字母，则直接加到后缀表达式中
            strcat(postfix, token);
        } else if (token[0] == '(') { // 如果是左括号，则加到操作符栈中
            stack_top++;
            stack[stack_top] = '(';
        } else if (token[0] == ')') { // 如果是右括号，则将栈中的操作符弹出，直到遇到左括号
            while (stack_top >= 0 && stack[stack_top] != '(') {
                postfix[strlen(postfix)] = stack[stack_top];
                stack_top--;
            }
            if (stack_top >= 0 && stack[stack_top] == '(') {
                stack_top--;
            }
        } else { // 如果是操作符
            while (stack_top >= 0 && precedence(stack[stack_top]) >= precedence(token[0])) {
                postfix[strlen(postfix)] = stack[stack_top];
                stack_top--;
            }
            stack_top++;
            stack[stack_top] = token[0];
        }
        token = strtok(NULL, " ");
    }
    while (stack_top >= 0) { // 将栈中剩余的操作符加到后缀表达式中
        postfix[strlen(postfix)] = stack[stack_top];
        stack_top--;
    }
    return postfix;
}
