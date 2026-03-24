#include <stdio.h>

#define MAXLINE 100
#define PAGELEN 50

int main(int argc, char *argv[])
{
    FILE *fp;
    char line[MAXLINE];
    int lineno, page;

    for (int i = 1; i < argc; i++)
    {
        fp = fopen(argv[i], "r");

        page = 1;
        lineno = 0;

        printf("\n==== %s ====\n", argv[i]);

        while (fgets(line, MAXLINE, fp))
        {
            if (lineno % PAGELEN == 0)
            {
                printf("\nPage %d\n", page++);
            }

            printf("%s", line);
            lineno++;
        }

        fclose(fp);
    }

    return 0;
}
