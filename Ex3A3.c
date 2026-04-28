#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 100   // độ dài tối đa của một dòng
#define PAGELEN 40    // số dòng trên mỗi trang

void printfile(FILE *fp, char *name);

int main(int argc, char *argv[])
{
    FILE *fp;
    int i;

    // kiểm tra số file nhập vào
    if (argc < 2)
    {
        printf("Usage: print file1 file2 ...\n");
        return 1;
    }

    // duyệt từng file
    for (i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");  // mở file

        if (fp == NULL)
        {
            printf("Cannot open %s\n", argv[i]);
            continue;
        }

        printfile(fp, argv[i]);  // gọi hàm in file
        fclose(fp);
    }

    return 0;
}

void printfile(FILE *fp, char *name)
{
    char line[MAXLINE];
    int lineno = 0;   // số dòng trong trang
    int page = 1;     // số trang

    // in tiêu đề trang
    printf("\n===== %s - Page %d =====\n", name, page);

    // đọc từng dòng trong file
    while (fgets(line, MAXLINE, fp))
    {
        // nếu hết trang
        if (lineno == PAGELEN)
        {
            page++;           // tăng trang
            lineno = 0;

            printf("\n===== %s - Page %d =====\n", name, page);
        }

        printf("%s", line);  // in dòng
        lineno++;
    }
}
