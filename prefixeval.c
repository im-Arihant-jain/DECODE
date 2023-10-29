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

int prefixEvaluation(char prefix[]) {
    Stack st;
    int len = strlen(prefix);

    initialise(&st);

    for (int i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isOperator(ch)) {
            int operand1 = top(&st);
            pop(&st);

            int operand2 = top(&st);
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

            push(&st, result);
        } else if (ch >= '0' && ch <= '9') {
            push(&st, ch - '0');
        }
    }

    return top(&st);
}

int main() {
    char prefix[] = "+*23*45";
    int result = prefixEvaluation(prefix);
    printf("Result of the prefix expression: %d\n", result);

    return 0;
}
