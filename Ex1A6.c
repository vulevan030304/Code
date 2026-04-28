#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_t > len_s)
        return 0;

    // So sánh từ cuối
    if (strcmp(s + len_s - len_t, t) == 0)
        return 1;

    return 0;
}

int main() {
    char s[] = "hello world";
    char t[] = "world";

    printf("%d\n", strend(s, t)); // 1

    return 0;
}
