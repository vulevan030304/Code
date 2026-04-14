#include <stdio.h>

int main() {
    int c;
    int freq[256] = {0};

    while ((c = getchar()) != EOF)
        freq[c]++;

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            printf("%c: ", i);
            for (int j = 0; j < freq[i]; j++)
                putchar('*');
            printf("\n");
        }
    }

    return 0;
}// dem so ky tu

