#include <stdio.h>
#define MAXLINE 1000

int main() {
    char line[MAXLINE];
    int c, len, i;

    while (1) {
        len = 0;

        while ((c = getchar()) != EOF && c != '\n') {
            if (len < MAXLINE - 1)
                line[len++] = c;
        }

        if (c == EOF && len == 0)
            break;

        i = len - 1;
        while (i >= 0 && (line[i] == ' ' || line[i] == '\t'))
            i--;

        if (i >= 0) {
            for (int j = 0; j <= i; j++)
                putchar(line[j]);
            putchar('\n');
        }

        if (c == EOF)
            break;
    }

    return 0;
}// xoa space tab cuoi dong bo dong trong
