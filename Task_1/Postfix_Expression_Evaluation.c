#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    scanf("%d", &n);

    while (n > 0) {
        int capacity = 1000;
        int stack[capacity];
        int top = -1;

        void push(int ele) {
            top++;
            stack[top] = ele;
        }

        int pop() {
            int ans = stack[top];
            top--;
            return ans;
        }

        int isEmpty() {
            return top == -1;
        }

        while (1) {
            char ele[1000];
            scanf("%s", ele);

            if (ele[0] == '?') {
                break;
            }

            // Check if the element is a number
            if (isdigit(ele[0]) || (ele[0] == '-' && isdigit(ele[1]))) {
                push(atoi(ele));
            } else {
                if (isEmpty()) {
                    return -1;
                }
                int ele1 = pop();
                if (isEmpty()) {
                    return -1;
                }
                int ele2 = pop();
                if (ele[0] == '+') {
                    push(ele1 + ele2);
                } else if (ele[0] == '-') {
                    push(ele2 - ele1);
                } else if (ele[0] == '*') {
                    push(ele1 * ele2);
                } else {
                    push(ele2 / ele1);
                }
            }
        }

        if (isEmpty()) {
            return -1;
        }

        printf("%d\n", pop());

        n--;
    }

    return 0;
}
