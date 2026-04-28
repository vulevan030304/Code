#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000   // độ dài tối đa của một dòng

int main(int argc, char *argv[])
{
    FILE *fp1, *fp2;        // con trỏ file
    char line1[MAXLINE];    // lưu dòng từ file1
    char line2[MAXLINE];    // lưu dòng từ file2
    int line = 1;           // đếm số dòng

    // kiểm tra số tham số khi chạy chương trình
    if (argc != 3)
    {
        printf("Usage: compare file1 file2\n");
        return 1;
    }

    // mở file ở chế độ đọc
    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");

    // kiểm tra lỗi mở file
    if (fp1 == NULL || fp2 == NULL)
    {
        printf("Cannot open file\n");
        return 1;
    }

    // đọc từng dòng của hai file
    while (fgets(line1, MAXLINE, fp1) && fgets(line2, MAXLINE, fp2))
    {
        // so sánh hai dòng
        if (strcmp(line1, line2) != 0)
        {
            printf("Files differ at line %d\n", line);
            printf("File1: %s", line1);
            printf("File2: %s", line2);
            return 0;
        }

        line++; // tăng số dòng
    }

    printf("Files are identical\n");

    fclose(fp1); // đóng file
    fclose(fp2);

    return 0;
}
