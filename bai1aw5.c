#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void display(struct node* head)
{
    struct node* temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}

int main()
{
    struct node* head = NULL;

    struct node* n1 = malloc(sizeof(struct node));
    struct node* n2 = malloc(sizeof(struct node));
    struct node* n3 = malloc(sizeof(struct node));

    n1->data = 10;
    n2->data = 20;
    n3->data = 30;

    n1->next = n2;
    n2->next = n3;
    n3->next = NULL;

    head = n1;

    display(head);

    return 0;
}
