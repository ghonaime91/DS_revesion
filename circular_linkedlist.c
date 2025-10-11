#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int value;
   struct node *next;  
} Node;

void push(Node**head, int val)
{

    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->next  = *head;
    newNode->value = val;

    if(*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
        return;
    }

    Node*temp = *head;
    while (temp->next != *head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return; 
    
}


int length(Node *head)
{
    Node*temp = head;
    if (head == NULL)
        return 0;

    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }

    return count;
    
}



void display(Node* head)
{
    if(head == NULL)
        return;
    Node*temp = head;
    do
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
    while (temp!= head);
    
}

void deleteFirstNode(Node**head)
{
    if(*head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }
    
     
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}


int main(void) {

        Node* head = NULL;
        push(&head,10);
        push(&head,20);
        push(&head,30);
        push(&head,40);
        push(&head,50);
        display(head);
    return 0;
}
