#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *);
struct node *insertNode(int);
struct node *deleteAtGivenPostion(struct node *, int);

struct node *insertNode(int size)
{
    struct node *head = NULL;
    struct node *currunt = NULL;
    struct node *newNode = NULL;

    for (int i = 0; i < size; i++)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value %d : ", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
            currunt = head;
        }
        else
        {
            currunt->next = newNode;
            currunt = currunt->next;
        }
    }

    printf("\nBefore delete the node at nth position,\n");
    return head;
}

struct node *deleteAtGivenPostion(struct node *head, int size)
{

    int position = 0;
    struct node *toDel = NULL;
    struct node *prevNode = NULL;
    toDel = head;

    printf("\nEnter the position you want to delete : ");
    scanf("%d", &position);

    if (position < 0 || position > size)
    {
        printf("Invalid position");
        return 0;
    }
    else if (position == 1)
    {
        toDel = head;
        head = head->next;
        free(toDel);
        return head;
    }
    else
    {
        for (int i = 0; i < position - 1 && toDel != NULL; i++)
        {
            prevNode = toDel;
            toDel = toDel->next;
        }
        prevNode->next = toDel->next;

        free(toDel);
        printf("After delete node,\n");
        return head;
    }
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int size = 0;
    struct node *head = NULL;

    printf("Enter the number of nodes in list : ");
    scanf("%d", &size);

    head = insertNode(size);
    display(head);

    head = deleteAtGivenPostion(head, size);
    display(head);

    return 0;
}

