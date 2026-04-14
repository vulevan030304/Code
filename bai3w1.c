#include <stdio.h>

int main() {
    int c;
    int spaces = 0, tabs = 0, newlines = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') spaces++;
        else if (c == '\t') tabs++;
        else if (c == '\n') newlines++;
    }

    printf("Spaces: %d\n", spaces);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", newlines);

    return 0;
}// dem space, tab,  newline
