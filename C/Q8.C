#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int data)
{

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;

    node->next = NULL;
    return node;
}

struct Node *copyList(struct Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }

    struct Node *curr = head;
    struct Node *newHead = NULL;
    struct Node *newTail = NULL;

    while (curr != NULL)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = curr->data;
        newNode->next = NULL;

        if (newHead == NULL)
        {
            newHead = newNode;
            newTail = newNode;
        }
        else
        {

            newTail->next = newNode;
            newTail = newNode;
        }

        curr = curr->next;
    }

    return newHead;
}

void displayList(struct Node *head)
{
    while (head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{

    struct Node *head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    printf("Original list: ");
    displayList(head);

    struct Node *copy = copyList(head);

    printf("Copied list: ");
    displayList(copy);

    return 0;
}