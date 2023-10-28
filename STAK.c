#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int top;
    unsigned capacity;
    char** array;
};

int isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

struct Stack* createStack(unsigned capacity) {  // arihant bhai aaye nhi aap 
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char**)malloc(stack->capacity * sizeof(char*));
    return stack;
}

void push(struct Stack* stack, char* item) {
    stack->array[++stack->top] = item;
}

char* pop(struct Stack* stack) {
    return stack->array[stack->top--];
}

char* prefixToPostfix(char* prefix) {
    int length = strlen(prefix);
    struct Stack* stack = createStack(length * 2); // Adjust capacity to ensure enough space for postfix
    if (!stack)
        return NULL;

    for (int i = length - 1; i >= 0; i--) {
        if (isOperand(prefix[i])) {
            char* operand = (char*)malloc( sizeof(char));
            operand[0] = prefix[i];
            operand[1]='\0';
            push(stack, operand);
        } else {
            char* op1 = pop(stack);
            char* op2 = pop(stack);
            char* postfix = (char*)malloc(4 * sizeof(char));
            strcpy(postfix, op1);
            strcat(postfix, op2);
            postfix[strlen(postfix)]=prefix[i];
            push(stack, postfix);
        }
    }
    return stack->array[0];
}

int main() {
    char prefix[] = "*-A/BC-/AKL";
    char* postfix = prefixToPostfix(prefix);
    printf("Prefix expression: %s\n", prefix);
    printf("Postfix expression: %s\n", postfix);
    return 0;
}
