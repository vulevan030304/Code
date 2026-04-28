#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc node
struct node {
    int data;              // giá trị của node
    struct node* next;     // con trỏ tới node tiếp theo
};

// ================== HIỂN THỊ DANH SÁCH ==================
void display(struct node* head) {
    // Duyệt từ head đến cuối (NULL)
    while (head != NULL) {
        printf("%d -> ", head->data); // in dữ liệu
        head = head->next;            // chuyển sang node tiếp theo
    }
    printf("NULL\n"); // kết thúc danh sách
}

// ================== THÊM NODE CUỐI ==================
struct node* insert(struct node* head, int data) {

    // Cấp phát bộ nhớ cho node mới
    struct node* newNode = (struct node*)malloc(sizeof(struct node));

    newNode->data = data;   // gán dữ liệu
    newNode->next = NULL;   // node cuối nên next = NULL

    // Nếu danh sách rỗng → node mới là head
    if (head == NULL)
        return newNode;

    // Duyệt đến node cuối
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Nối node cuối với node mới
    temp->next = newNode;

    return head; // trả về head ban đầu
}

// ================== TÌM KIẾM ==================
struct node* search(struct node* head, int data) {

    // Duyệt từng node
    while (head != NULL) {

        // Nếu tìm thấy
        if (head->data == data)
            return head;

        head = head->next;
    }

    // Không tìm thấy
    return NULL;
}

// ================== XÓA NODE ==================
struct node* deleteNode(struct node* head, int data) {

    struct node* temp = head; // node hiện tại
    struct node* prev = NULL; // node phía trước

    // Tìm node cần xóa
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // Nếu không tìm thấy
    if (temp == NULL)
        return head;

    // Nếu xóa node đầu
    if (prev == NULL) {
        head = temp->next;
    } else {
        // Bỏ qua node cần xóa
        prev->next = temp->next;
    }

    free(temp); // giải phóng bộ nhớ

    return head;
}

// ================== GIẢI PHÓNG DANH SÁCH ==================
void freeList(struct node* head) {

    struct node* temp;

    // Duyệt từng node và free
    while (head != NULL) {
        temp = head;        // lưu node hiện tại
        head = head->next;  // chuyển sang node tiếp theo
        free(temp);         // giải phóng node
    }
}

// ================== HÀM MAIN TEST ==================
int main() {

    struct node* head = NULL; // danh sách ban đầu rỗng

    // Thêm phần tử
    head = insert(head, 1);
    head = insert(head, 2);
    head = insert(head, 3);

    display(head); // 1 -> 2 -> 3 -> NULL

    // Tìm kiếm
    struct node* found = search(head, 2);
    if (found != NULL)
        printf("Found: %d\n", found->data);
    else
        printf("Not found\n");

    // Xóa phần tử
    head = deleteNode(head, 2);
    display(head); // 1 -> 3 -> NULL

    // Giải phóng bộ nhớ
    freeList(head);

    return 0;
}
