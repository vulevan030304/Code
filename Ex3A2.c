#include <stdio.h>

/* Hàm mở rộng chuỗi dạng a-d thành abcd */
void expand(char s1[], char s2[])
{
    int i, j = 0;

    for(i = 0; s1[i] != '\0'; i++)
    {
        /* nếu gặp dấu - */
        if(s1[i] == '-' && i > 0 && s1[i+1] != '\0')
        {
            char start = s1[i-1];   // ký tự trước -
            char end = s1[i+1];     // ký tự sau -

            /* nếu đúng khoảng */
            if(start < end)
            {
                char c;

                for(c = start + 1; c <= end; c++)
                {
                    s2[j++] = c;   // thêm các ký tự ở giữa
                }

                i++; // bỏ qua ký tự cuối
            }
        }
        else
        {
            s2[j++] = s1[i];  // copy ký tự bình thường
        }
    }

    s2[j] = '\0'; // kết thúc chuỗi
}

int main()
{
    char s1[] = "a-d-f";
    char s2[100];

    expand(s1, s2);

    printf("Expanded = %s\n", s2);

    return 0;
}
