#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* đảo chuỗi */
void reverse(char s[])
{
    int i, j;
    char temp;

    for(i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

/* chuyển số n sang cơ số b */
void itob(int n, char s[], int b)
{
    int i = 0;
    int sign = n;

    do
    {
        int digit = abs(n % b);  // lấy phần dư

        /* nếu <10 thì là số */
        if(digit < 10)
            s[i++] = digit + '0';
        else
            s[i++] = digit - 10 + 'A';  // A,B,C...

        n /= b;  // chia tiếp

    } while(n != 0);

    /* thêm dấu âm nếu cần */
    if(sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}

int main()
{
    char s[100];

    itob(15, s, 2);
    printf("15 base2 = %s\n", s);

    itob(255, s, 16);
    printf("255 base16 = %s\n", s);

    return 0;
}
