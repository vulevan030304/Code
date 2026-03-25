#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* addback(struct node* head, int data)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->next = NULL;

    if(head == NULL)
        return newnode;

    struct node* temp = head;

    while(temp->next != NULL)
        temp = temp->next;

    temp->next = newnode;

    return head;
}

int main()
{
    struct node* head = NULL;

    head = addback(head,10);
    head = addback(head,20);

    printf("Program ran successfully\n");

    return 0;
}
