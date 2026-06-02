#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *new_Node(int data)
{

    struct Node *node = (struct Node *)malloc(sizeof(struct Node));

    node->data = data;

    node->next = NULL;
    return node;
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

struct Node *Nodes_From_End(struct Node *head, int n)
{
    struct Node *slow_ptr = head, *fast_ptr = head;
    int ctr = 0;

    while (fast_ptr != NULL)
    {
        fast_ptr = fast_ptr->next;

        if (ctr >= n)
        {
            slow_ptr = slow_ptr->next;
        }
        ctr++;
    }

    if (ctr < n)
        return NULL;
    return slow_ptr;
}

int main()
{
    struct Node *result;
    struct Node *list1 = new_Node(1);
    list1->next = new_Node(3);
    list1->next->next = new_Node(5);
    list1->next->next->next = new_Node(7);
    list1->next->next->next->next = new_Node(9);
    list1->next->next->next->next->next = new_Node(11);

    printf("Original list:\n");
    displayList(list1);

    printf("Last 2 nodes from the end of the said singly list:\n");
    result = Nodes_From_End(list1, 2);
    displayList(result);

    printf("Last 3 nodes from the end of the said singly list:\n");
    result = Nodes_From_End(list1, 3);
    displayList(result);

    printf("Last 4 nodes from the end of the said singly list:\n");
    result = Nodes_From_End(list1, 4);
    displayList(result);

    printf("Last 1 node from the end of the said singly list:\n");
    result = Nodes_From_End(list1, 1);
    displayList(result);

    printf("Last 5 node from the end of the said singly list:\n");
    result = Nodes_From_End(list1, 5);
    displayList(result);

    return 0;
}