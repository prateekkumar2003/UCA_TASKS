typedef struct {
    char* arr;
    int top;
} Stack;

void createStack(Stack* stack, int size) {
    stack->arr = (char*)malloc(size * sizeof(char));
    stack->top = 0;
}

int isEmpty(Stack* stack) {
    return stack->top == 0;
}

void push(Stack* stack, char ele) {
    stack->arr[stack->top] = ele;
    stack->top++;
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0'; 
    }
    return stack->arr[stack->top - 1];
}

bool isValid(char* s) {
    int n = strlen(s);
    Stack* st = (Stack*)malloc(sizeof(Stack));
    createStack(st, n);
    
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            push(st, ch);
        } else {
            char top = peek(st);
            if ((top == '(' && ch == ')') || (top == '[' && ch == ']') || (top == '{' && ch == '}')) {
                st->top--; 
            } else {
                free(st->arr);
                free(st);
                return false;
            }
        }
    }

    bool result = isEmpty(st);
    free(st->arr);
    free(st);
    return result;
}
