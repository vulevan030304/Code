#include <stdio.h>

int main() {

    int i, j = 5;

    for (i = 0; i < 10; i++) {
        if (j <= 0)
            break;

        printf("i = %d\n", i);
        j--;
    }

    return 0;
}// viet lai vong lap for ko dung and or
