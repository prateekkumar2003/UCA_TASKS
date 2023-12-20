
struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) {
        return '\0'; // Empty stack
    }
    char data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

bool isValid(char* s) {
    struct Stack stack;
    stack.top = NULL;
    int idx = 0;

    // If the string is empty, return true...
    if (s[0] == '\0') {
        return true;
    }

    // Create a loop to check parentheses...
    while (s[idx] != '\0') {
        // If it contains the below parentheses, push the char to stack...
        if (s[idx] == '(' || s[idx] == '[' || s[idx] == '{') {
            push(&stack, s[idx]);
        }
        // If the current char is a closing brace provided, pop the top element...
        // Stack is not empty...
        else if ((s[idx] == ')' && stack.top != NULL && stack.top->data == '(') ||
                 (s[idx] == '}' && stack.top != NULL && stack.top->data == '{') ||
                 (s[idx] == ']' && stack.top != NULL && stack.top->data == '[')) {
            pop(&stack);
        } else {
            return false; // If the string is not a valid parenthesis...
        }
        idx++; // Increase the index...
    }

    // If stack.top is NULL, return true...
    if (stack.top == NULL) {
        return true;
    }
    return false;
}