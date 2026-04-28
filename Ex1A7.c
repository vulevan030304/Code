#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10   // kích thước bảng băm

// Cấu trúc node (danh bạ)
typedef struct Node {
    char name[50];
    char phone[20];
    struct Node* next;   // dùng cho chaining (danh sách liên kết)
} Node;

// Bảng băm
Node* hashTable[TABLE_SIZE];

// ================= HASH FUNCTION =================
// Hàm băm: tính tổng ASCII rồi mod TABLE_SIZE
int hash(char *str) {
    int sum = 0;
    for (int i = 0; str[i]; i++) {
        sum += str[i];
    }
    return sum % TABLE_SIZE;
}

// ================= INSERT =================
void insert(char *name, char *phone) {
    int index = hash(name);

    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = NULL;

    // thêm vào đầu danh sách (chaining)
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("✔ Inserted: %s - %s\n", name, phone);
}

// ================= SEARCH =================
void search(char *name) {
    int index = hash(name);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("✔ Found: %s - %s\n", name, temp->phone);
            return;
        }
        temp = temp->next;
    }

    printf("❌ Not found: %s\n", name);
}

// ================= DELETE =================
void delete(char *name) {
    int index = hash(name);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            if (prev == NULL)
                hashTable[index] = temp->next;
            else
                prev->next = temp->next;

            free(temp);
            printf("✔ Deleted: %s\n", name);
            return;
        }
        prev = temp;
        temp = temp->next;
    }

    printf("❌ Cannot delete (not found): %s\n", name);
}

// ================= PRINT =================
void printTable() {
    printf("\n--- HASH TABLE ---\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("(%s,%s) -> ", temp->name, temp->phone);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ================= MAIN =================
int main() {
    // khởi tạo bảng
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    // nhập thử dữ liệu
    insert("An", "111");
    insert("Binh", "222");
    insert("Cuong", "333");
    insert("Dung", "444");
    insert("Em", "555");
    insert("Phuc", "666");
    insert("Giang", "777");
    insert("Hoa", "888");

    printTable();

    // test search
    search("An");
    search("XYZ");  // không tồn tại

    // test delete
    delete("Binh");
    delete("XYZ");

    printTable();

    return 0;
}
