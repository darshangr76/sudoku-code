#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

// Insert at beginning
void insert()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter data: ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

// Delete from beginning
void delete()
{
    struct node *temp;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted element = %d\n", temp->data);
    free(temp);
}

// Search
void search()
{
    struct node *temp;
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    temp = head;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("Element found\n");
            return;
        }
        temp = temp->next;
    }

    printf("Element not found\n");
}

// Display
void display()
{
    struct node *temp = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int main()
{
    insert();
    insert();
    insert();

    display();

    search();

    delete();

    display();

    return 0;
}