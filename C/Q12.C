
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int addWithCarry(struct Node *head)
{

    if (head == NULL)
    {
        return 1;
    }

    int res = head->data + addWithCarry(head->next);

    head->data = res % 10;
    return res / 10;
}

struct Node *addOne(struct Node *head)
{

    int carry = addWithCarry(head);

    if (carry)
    {
        struct Node *newNode = createNode(carry);
        newNode->next = head;
        return newNode;
    }
    return head;
}

void printList(struct Node *head)
{
    struct Node *curr = head;
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{

    struct Node *head = createNode(1);
    head->next = createNode(9);
    head->next->next = createNode(9);
    head->next->next->next = createNode(9);

    printf("Original list is: ");
    printList(head);

    head = addOne(head);

    printf("Resultant list is: ");
    printList(head);

    return 0;
}