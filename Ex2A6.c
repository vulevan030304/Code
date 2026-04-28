#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 100

char *lines[MAXLINES];

int numcmp(const char *s1, const char *s2) {
    return atof(s1) - atof(s2);
}

int charcmp(const char *s1, const char *s2) {
    return strcmp(s1, s2);
}

void mysort(int n, int numeric) {
    int i, j;
    char *temp;

    for (i = 0; i < n-1; i++) {
        for (j = i+1; j < n; j++) {
            int cmp = numeric ? numcmp(lines[i], lines[j])
                              : charcmp(lines[i], lines[j]);

            if (cmp > 0) {
                temp = lines[i];
                lines[i] = lines[j];
                lines[j] = temp;
            }
        }
    }
}

int main() {
    int n = 0;
    int numeric = 0;
    char buffer[100];

    printf("Nhap cac dong (Ctrl+D de ket thuc):\n");

    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        lines[n] = strdup(buffer);
        n++;
    }

    // giả sử có option -n
    numeric = 1;

    mysort(n, numeric);

    printf("\nSau khi sap xep:\n");
    for (int i = 0; i < n; i++)
        printf("%s", lines[i]);

    return 0;
}
