#include <stdio.h>
#include <limits.h>

int main() {

    printf("===== CHAR =====\n");
    printf("Signed char: %d -> %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char: 0 -> %u\n", UCHAR_MAX);

    printf("\n===== SHORT =====\n");
    printf("Signed short: %d -> %d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short: 0 -> %u\n", USHRT_MAX);

    printf("\n===== INT =====\n");
    printf("Signed int: %d -> %d\n", INT_MIN, INT_MAX);
    printf("Unsigned int: 0 -> %u\n", UINT_MAX);

    printf("\n===== LONG =====\n");
    printf("Signed long: %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long: 0 -> %lu\n", ULONG_MAX);

    return 0;
}// in ra gia tri mix max cua cac kieu du lieu
