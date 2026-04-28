//b
#include <stdio.h>
#include <stdlib.h>

/* Hàm sinh số thực ngẫu nhiên trong khoảng [0,1] */
double rand_double()
{
    double ret = (double)rand();     // lấy số ngẫu nhiên
    return ret/(RAND_MAX+1.0);       // chuẩn hóa về [0,1]
}

/* Hàm lấy mẫu phân bố hình học */
int sample_geometric_rv(double p)
{
    double q = rand_double();  // sinh số ngẫu nhiên đầu tiên
    int n = 1;                 // biến đếm số lần thử

    /* lặp khi q vẫn >= p */
    while(q >= p)
    {
        q = rand_double();     // sinh số mới
        n++;                   // tăng số lần thử
    }

    return n;                  // trả về kết quả
}

int main()
{
    printf("Sample = %d\n", sample_geometric_rv(0.5));
    return 0;
}
