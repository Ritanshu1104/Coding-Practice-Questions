#include <stdio.h>
#include <stdlib.h>

// Structure defining a node in a singly linked list
struct Node
{
    int data;
    struct Node *next;
};

// Function to create a new node with given data
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to remove duplicates from an unsorted linked list using nested loops
struct Node *removeDuplicates(struct Node *head)
{
    struct Node *curr1 = head;

    // Traverse each node in the list
    while (curr1 != NULL)
    {
        struct Node *curr2 = curr1;

        // Traverse the remaining nodes to find and remove duplicates
        while (curr2->next != NULL)
        {
            // Check if the next node has the same data as the current node
            if (curr2->next->data == curr1->data)
            {
                // Duplicate found, remove it
                struct Node *duplicate = curr2->next;
                curr2->next = curr2->next->next;
                free(duplicate);
            }
            else
            {
                // Move to the next node
                curr2 = curr2->next;
            }
        }
        // Move to the next node in the list
        curr1 = curr1->next;
    }
    return head;
}

// Function to print the elements of a linked list
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

// Main function to demonstrate removing duplicates from an unsorted linked list
int main()
{
    // Create a singly linked list: 12 -> 11 -> 12 -> 21 -> 41 -> 43 -> 21
    struct Node *head = newNode(12);
    head->next = newNode(11);
    head->next->next = newNode(12);
    head->next->next->next = newNode(21);
    head->next->next->next->next = newNode(41);
    head->next->next->next->next->next = newNode(43);
    head->next->next->next->next->next->next = newNode(21);

    printf("Original unsorted linked list:\n");
    printList(head);

    // Remove duplicates
    head = removeDuplicates(head);

    printf("Linked list after removing duplicates:\n");
    printList(head);

    return 0;
}