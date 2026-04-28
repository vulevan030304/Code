#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

typedef struct Node {
    char word[50];
    int count;
    struct Node *next;
} Node;

Node *table[SIZE];

// Hash function
unsigned int hash(char *word) {
    unsigned int h = 0;
    while (*word)
        h = h * 31 + *word++;
    return h % SIZE;
}

// Lookup function
Node *lookup(char *word) {
    unsigned int index = hash(word);
    Node *cur = table[index];

    while (cur != NULL) {
        if (strcmp(cur->word, word) == 0) {
            return cur;
        }
        cur = cur->next;
    }

    // Nếu chưa có → tạo mới
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->count = 0;
    newNode->next = table[index];
    table[index] = newNode;

    return newNode;
}

// Free memory
void cleantable() {
    for (int i = 0; i < SIZE; i++) {
        Node *cur = table[i];
        while (cur != NULL) {
            Node *temp = cur;
            cur = cur->next;
            free(temp);
        }
        table[i] = NULL;
    }
}

int main() {
    char *words[] = {"apple", "banana", "apple", "orange", "banana", "apple"};
    int n = 6;

    for (int i = 0; i < SIZE; i++)
        table[i] = NULL;

    // Đếm từ
    for (int i = 0; i < n; i++) {
        Node *node = lookup(words[i]);
        node->count++;
    }

    // In kết quả
    for (int i = 0; i < SIZE; i++) {
        Node *cur = table[i];
        while (cur != NULL) {
            printf("%s: %d\n", cur->word, cur->count);
            cur = cur->next;
        }
    }

    // Giải phóng bộ nhớ
    cleantable();

    return 0;
}
