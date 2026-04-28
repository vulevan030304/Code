#include <stdio.h>

#define MAXVAL 100   // kích thước tối đa của stack

int sp = 0;          // stack pointer
double val[MAXVAL];  // mảng lưu stack

/* Hàm push: đưa phần tử vào stack */
void push(double f)
{
    if(sp < MAXVAL)
    {
        val[sp++] = f;   // thêm phần tử và tăng sp
    }
    else
    {
        printf("Error: stack full\n");
    }
}

/* Hàm pop: lấy phần tử trên cùng */
double pop(void)
{
    if(sp > 0)
    {
        return val[--sp];   // giảm sp rồi trả về giá trị
    }
    else
    {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

int main()
{
    char cmd;

    /* thêm vài giá trị vào stack để test */
    push(10);
    push(20);
    push(30);

    printf("Nhap lenh (?, d, s, c): ");

    while((cmd = getchar()) != EOF)
    {
        switch(cmd)
        {

            /* in phần tử top */
            case '?':
                if(sp > 0)
                    printf("Top = %.2f\n", val[sp-1]);
                else
                    printf("Stack empty\n");
                break;

            /* duplicate phần tử top */
            case 'd':
                if(sp > 0)
                {
                    push(val[sp-1]);   // push lại giá trị top
                }
                break;

            /* swap 2 phần tử trên cùng */
            case 's':
                if(sp > 1)
                {
                    double temp;
                    temp = val[sp-1];
                    val[sp-1] = val[sp-2];
                    val[sp-2] = temp;
                }
                else
                    printf("Not enough elements\n");
                break;

            /* clear stack */
            case 'c':
                sp = 0;
                printf("Stack cleared\n");
                break;
        }
    }

    return 0;
}
