#include <stdio.h>
#include <string.h>

struct stack {
    int arr[10];
    int size;
};

typedef struct stack Stack;

void initialise(Stack *st) {
    st->size = 0;
    st->arr[st->size] = -1;
}

int isEmpty(Stack *st) {
    if (st->size == 0) {
        return 1;
    }
    return 0;
}

void push(Stack *st, int ele) {
    (st->size)++;
    st->arr[st->size] = ele;
}

void pop(Stack *st) {
    if (isEmpty(st)) {
        printf("Can't pop\n");
        return;
    }
    (st->size)--;
}

int top(Stack *st) {
    return st->arr[st->size];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int postfixEvaluation(char postfix[]) {
    Stack st;
    int len = strlen(postfix);

    initialise(&st);

    for (int i = 0; i < len; i++) {
        char ch = postfix[i];

        if (!isOperator(ch)) {
            // If it's an operand, push it onto the stack
            push(&st, ch - '0');
        } else {
            // If it's an operator, pop the top two operands from the stack
            int operand2 = top(&st);
            pop(&st);

            int operand1 = top(&st);
            pop(&st);

            int result;
            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }

            // Push the result back onto the stack
            push(&st, result);
        }
    }

    return top(&st);
}

int main() {
    char postfix[] = "23*45*+";
    int result = postfixEvaluation(postfix);
    printf("Result of the postfix expression: %d\n", result);

    return 0;
}
