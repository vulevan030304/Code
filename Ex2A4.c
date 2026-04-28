#include <stdio.h>
#include <stdlib.h>

// Định nghĩa node của cây
struct tnode {
    int data;               // dữ liệu
    struct tnode* left;     // con trái
    struct tnode* right;    // con phải
};

// ================== TẠO NODE ==================
struct tnode* createNode(int data) {

    // Cấp phát bộ nhớ
    struct tnode* newNode = (struct tnode*)malloc(sizeof(struct tnode));

    newNode->data = data;
    newNode->left = NULL;   // chưa có con
    newNode->right = NULL;

    return newNode;
}

// ================== THÊM NODE (BST) ==================
struct tnode* addnode(struct tnode* root, int data) {

    // Nếu cây rỗng → tạo node mới
    if (root == NULL)
        return createNode(data);

    // Nếu nhỏ hơn → sang trái
    if (data < root->data)
        root->left = addnode(root->left, data);

    // Nếu lớn hơn → sang phải
    else
        root->right = addnode(root->right, data);

    return root;
}

// ================== DUYỆT PREORDER ==================
void preorder(struct tnode* root) {

    if (root != NULL) {
        printf("%d ", root->data);   // Node
        preorder(root->left);        // Left
        preorder(root->right);       // Right
    }
}

// ================== DUYỆT INORDER ==================
void inorder(struct tnode* root) {

    if (root != NULL) {
        inorder(root->left);         // Left
        printf("%d ", root->data);   // Node
        inorder(root->right);        // Right
    }
}

// ================== XÓA TOÀN BỘ CÂY ==================
int deleteTree(struct tnode* root) {

    if (root == NULL)
        return 0;

    int count = 1; // đếm node hiện tại

    // Xóa cây con trái và phải trước
    count += deleteTree(root->left);
    count += deleteTree(root->right);

    free(root); // giải phóng node

    return count;
}

// ================== HÀM MAIN TEST ==================
int main() {

    struct tnode* root = NULL;

    // Thêm node
    root = addnode(root, 5);
    root = addnode(root, 3);
    root = addnode(root, 7);
    root = addnode(root, 1);

    // Duyệt cây
    printf("Preorder: ");
    preorder(root);

    printf("\nInorder: ");
    inorder(root);

    // Xóa cây
    int total = deleteTree(root);
    printf("\nDeleted nodes: %d\n", total);

    return 0;
}
