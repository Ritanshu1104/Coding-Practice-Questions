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

void detect_and_remove_Loop(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (slow == fast)
    {
        slow = head;

        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = NULL;
    }
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

    printf("Original singly linked list:\n");
    displayList(head);

    printf("\nCreating a loop:\n");
    head->next->next->next->next->next = head->next->next;

    printf("\nAfter removing the loop:\n");
    detect_and_remove_Loop(head);
    displayList(head);

    return 0;
}