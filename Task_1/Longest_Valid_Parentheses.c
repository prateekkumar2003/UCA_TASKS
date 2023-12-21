#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    int* arr;
    int top;
} Stack;

void createStack(Stack* stack, int size) {
    stack->arr = (int*)malloc(size * sizeof(int));
    stack->top = 0; 
}

bool isEmpty(Stack* stack) {
    return stack->top == 0;
}

void push(Stack* stack, int ele) {
    stack->arr[stack->top++] = ele;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->arr[--stack->top];
}

int peek(Stack* stack) {
    return stack->arr[stack->top - 1];
}

int longestValidParentheses(char* s) {
    int n = strlen(s);
    if (n == 0) {
        return 0;
    }

    Stack* st = (Stack*)malloc(sizeof(Stack));
    createStack(st, n + 1);
    int maxi = 0;

    push(st, -1);

    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(') {
            push(st, i);
        } else {
            pop(st);
            if (isEmpty(st)) {
                push(st, i);
            } else {
                maxi = (i - peek(st) > maxi) ? i - peek(st) : maxi;
            }
        }
    }
    free(st->arr);
    free(st);
    return maxi;
}

int main(){
    char* str;
    scanf("%s",str);
    printf("%d",longestValidParentheses(str));
}