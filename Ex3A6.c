#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXSTACK 100

double stack[MAXSTACK];
int top = 0;

void push(double val) {
    stack[top++] = val;
}

double pop() {
    return stack[--top];
}

int main(int argc, char *argv[]) {
    int i;
    double op2;

    for (i = 1; i < argc; i++) {
        if (isdigit(argv[i][0])) {
            push(atof(argv[i]));
        } else {
            switch (argv[i][0]) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                default:
                    printf("Loi: toan tu khong hop le\n");
                    return 1;
            }
        }
    }

    printf("Ket qua: %.2f\n", pop());
    return 0;
}
