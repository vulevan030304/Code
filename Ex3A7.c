#include <stdio.h>

#define MAX 100

// cấu trúc bệnh nhân
typedef struct {
    char name[50];
    int priority;
} Patient;

Patient heap[MAX];
int size = 0;

// ================= SWAP =================
void swap(Patient *a, Patient *b) {
    Patient temp = *a;
    *a = *b;
    *b = temp;
}

// ================= HEAPIFY UP =================
// dùng khi insert
void heapifyUp(int i) {
    while (i > 0 && heap[(i - 1)/2].priority < heap[i].priority) {
        swap(&heap[i], &heap[(i - 1)/2]);
        i = (i - 1)/2;
    }
}

// ================= HEAPIFY DOWN =================
// dùng khi pop
void heapifyDown(int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left < size && heap[left].priority > heap[largest].priority)
        largest = left;

    if (right < size && heap[right].priority > heap[largest].priority)
        largest = right;

    if (largest != i) {
        swap(&heap[i], &heap[largest]);
        heapifyDown(largest);
    }
}

// ================= PUSH =================
void push(char *name, int priority) {
    heap[size].priority = priority;
    sprintf(heap[size].name, "%s", name);
    size++;

    heapifyUp(size - 1);
}

// ================= POP =================
void pop() {
    if (size == 0) {
        printf("Empty heap\n");
        return;
    }

    printf("Serving: %s (%d)\n", heap[0].name, heap[0].priority);

    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);
}

// ================= PEEK =================
void peek() {
    if (size == 0) {
        printf("Empty\n");
        return;
    }
    printf("Top: %s (%d)\n", heap[0].name, heap[0].priority);
}

// ================= PRINT =================
void printHeap() {
    printf("\nHeap:\n");
    for (int i = 0; i < size; i++) {
        printf("%s (%d)\n", heap[i].name, heap[i].priority);
    }
}

// ================= MAIN =================
int main() {
    push("BenhNhanA", 5);
    push("BenhNhanB", 9);
    push("BenhNhanC", 3);
    push("BenhNhanD", 7);
    push("BenhNhanE", 8);

    printHeap();

    peek();

    // xử lý lần lượt
    while (size > 0) {
        pop();
    }

    return 0;
}
