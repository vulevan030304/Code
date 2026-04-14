#include <stdio.h>
#include <ctype.h>

int htoi(char s[]) {
    int i = 0;
    int result = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    for (; s[i] != '\0'; i++) {

        if (s[i] == '\n')
            break;

        result *= 16;

        if (isdigit(s[i]))
            result += s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            result += s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            result += s[i] - 'A' + 10;
        else
            return -1;
    }

    return result;
}

int main() {
    char hex[100];

    printf("Nhap so hexa: ");
    fgets(hex, sizeof(hex), stdin);

    printf("Gia tri thap phan = %d\n", htoi(hex));

    return 0;
}// chuyen mot he so 16 sang he 10
