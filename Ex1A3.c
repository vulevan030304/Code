#include <stdio.h>      // thư viện nhập xuất chuẩn
#include <ctype.h>      // thư viện xử lý ký tự (toupper, tolower)
#include <string.h>     // thư viện xử lý chuỗi

int main(int argc, char *argv[])
{
    int c;  // biến lưu từng ký tự đọc vào

    // argv[0] chứa tên chương trình khi chạy
    // nếu tên chương trình có chữ "lower"
    if (strstr(argv[0], "lower") != NULL)
    {
        // đọc từng ký tự từ input
        while ((c = getchar()) != EOF)
        {
            // chuyển sang chữ thường rồi in ra
            putchar(tolower(c));
        }
