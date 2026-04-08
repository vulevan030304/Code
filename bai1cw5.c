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

struct node* find(struct node* head, int data)
{
    struct node* temp = head;

    while(temp != NULL)
    {
        if(temp->data == data)
            return temp;

        temp = temp->next;
    }

    return NULL;
}

int main()
{
    struct node* head = NULL;

    head = addback(head,10);
    head = addback(head,20);
    head = addback(head,30);

    struct node* result = find(head,20);

    if(result != NULL)
        printf("Found: %d\n", result->data);
    else
        printf("Not found\n");

    return 0;
}
