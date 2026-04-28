#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Hàm đảo chuỗi */
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

/* Hàm chuyển số nguyên thành chuỗi */
void itoa_fix(int n, char s[])
{
    int i = 0;
    int sign = n;  // lưu dấu của n

    /* tách từng chữ số */
    do
    {
        s[i++] = abs(n % 10) + '0'; // chuyển số sang ký tự
        n /= 10;                    // bỏ chữ số cuối
    }
    while(n != 0);

    /* nếu số âm thì thêm dấu - */
    if(sign < 0)
        s[i++] = '-';

    s[i] = '\0';   // kết thúc chuỗi

    reverse(s);    // đảo chuỗi lại
}

int main()
{
    char s[100];

    itoa_fix(-12345, s);

    printf("Result = %s\n", s);

    return 0;
}
