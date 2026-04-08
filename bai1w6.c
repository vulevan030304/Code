#include <stdio.h>
#include <string.h>

int strend(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    if (len_t > len_s)
        return 0;

    // So sánh phần cuối của s với t
    return strcmp(s + (len_s - len_t), t) == 0;
}

int main() {
    printf("%d\n", strend("hello", "lo"));  // 1
    printf("%d\n", strend("hello", "he"));  // 0
    return 0;
}
