#include <stdio.h>
#include <stdlib.h>

// Link list node
struct Node {
    int data;
    struct Node* next;
};

// Function to find the middle element of the linked list using the two-pointer technique
void printMiddle(struct Node* head) {
    // Initialize two pointers to the head of the list
    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;

    // Traverse the list with two pointers
    // The fast pointer moves two steps at a time, while the slow pointer moves one step at a time
    // When the fast pointer reaches the end, the slow pointer will be at the middle
    while (fast_ptr != NULL && fast_ptr->next != NULL) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // Print the data of the middle node
    printf("The middle element is [%d]\n", slow_ptr->data);
}

// Function to insert a new node at the beginning of the list
void push(struct Node** head_ref, int new_data) {
    // Allocate memory for the new node
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    // Assign data to the new node
    new_node->data = new_data;
    // Link the new node to the current head
    new_node->next = *head_ref;
    // Update the head to point to the new node
    *head_ref = new_node;
}


void printList(struct Node* ptr) {
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}


int main() {

    struct Node* head = NULL;


    for (int i = 5; i > 0; i--) {
        push(&head, i);
        printList(head);
    }

    printMiddle(head);

    return 0;
}   