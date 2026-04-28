#include <stdio.h>

#define SIZE 10   // kích thước mảng

// khai báo mảng toàn cục
int arr[SIZE] = {9, 3, 7, 1, 6, 2, 8, 5, 4, 0};

// hàm trả về độ dài mảng
int array_length(int a[])
{
    return SIZE;
}

/*
 shift_element()
 pElement: con trỏ trỏ đến phần tử đang sai vị trí
 Hàm sẽ dịch phần tử này về đúng vị trí bên trái
*/
void shift_element(int *pElement)
{
    int value = *pElement;  // lưu giá trị cần chèn
    int *p = pElement;      // con trỏ dùng để duyệt

    // dịch các phần tử lớn hơn value sang phải
    while (p > arr && *(p - 1) > value)
    {
        *p = *(p - 1);  // copy phần tử trước sang
        p--;            // lùi con trỏ
    }

    // chèn value vào đúng vị trí
    *p = value;
}

/*
 insertion_sort()
 duyệt mảng từ trái sang phải
 nếu phần tử nhỏ hơn phần tử trước thì gọi shift_element
*/
void insertion_sort(void)
{
    int len = array_length(arr);
    int *p;

    // bắt đầu từ phần tử thứ 2
    for (p = arr + 1; p < arr + len; p++)
    {
        if (*p < *(p - 1))
        {
            shift_element(p);
        }
    }
}

// hàm in mảng
void print_array()
{
    int *p;

    for (p = arr; p < arr + SIZE; p++)
    {
        printf("%d ", *p);
    }

    printf("\n");
}

int main()
{
    printf("Array before sorting:\n");
    print_array();

    insertion_sort();

    printf("Array after sorting:\n");
    print_array();

    return 0;
}
