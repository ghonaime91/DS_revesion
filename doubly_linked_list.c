#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int value;
   struct node *next;  
   struct node *previous;
} Node;

typedef struct linked_list
{
    Node *head;
    Node* tail;
}List;


void push(List **list, int val)
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value    = val;
    newNode->next     = NULL;
    newNode->previous = NULL;

    if((*list)->head == NULL)
    {
        (*list)->head = (*list)->tail = newNode;
        return;
    }
    newNode->previous = (*list)->tail;
    (*list)->tail->next = newNode;
    (*list)->tail = newNode;

    return;
}


void insertFirst(List ** list, int val)
{

    if((*list)->head == NULL)
    {
        push(list,val);
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value    = val;
    newNode->previous = NULL;
    newNode->next     = (*list)->head;
    (*list)->head->previous = newNode;
    (*list)->head = newNode;
    return;

}

int length(List *list)
{
    if(list->head == NULL)
        return 0;
    int count = 0;

    Node* temp = list->head;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    
    return count;

}


void insertAtPos(List**list, int pos, int val)
{

    int len = length(*list);

    if(pos < 1 || pos > len )
    {
        printf("Bad Location\n");
        return;
    }


    if((*list)->head == NULL || pos == len+1)
    {
        push(list, val);
        return;
    }
    
    else if (pos == 1)
    {
        insertFirst(list, val);
        return;
    }
    
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value    = val;
    newNode->next     = NULL;
    newNode->previous = NULL;

    Node*temp = (*list)->head;
    int i = 1;
    while (i < pos-1)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->previous = temp;
    temp->next->previous = newNode;
    temp->next = newNode;
    return;
    
}


void insertAfterPos(List**list, int pos, int val)
{
    int len = length(*list);

    if(pos < 1 || pos > len )
    {
        printf("Bad Location\n");
        return;
    }


    if((*list)->head == NULL || pos == len )
    {
        push(list, val);
        return;
    }
    
    
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value    = val;
    newNode->next     = NULL;
    newNode->previous = NULL;

    Node*temp = (*list)->head;
    int i = 1;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->previous = temp;

    if(temp->next != NULL)
        temp->next->previous = newNode;
    else
    (*list)->tail = newNode;
    
    temp->next = newNode;

    return;
    
}


void deleteFirst(List **list)
{
    if((*list)->head == NULL)
    {
        printf("The List Is Empty\n");
        return;
    }

    if((*list)->head->next == NULL)
    {
        (*list)->head = (*list)->tail = NULL;
        return;
    }

    Node *temp = (*list)->head;
    (*list)->head = (*list)->head->next;
    (*list)->head->previous = NULL;
    free(temp);
    return;
}

void deleteLast(List**list)
{
    if((*list)->head == NULL)
    {
        printf("The List Is Empty\n");
        return;
    }

    if((*list)->head->next == NULL)
    {
        (*list)->head = (*list)->tail = NULL;
        return;
    }

    Node *temp = (*list)->tail;
    (*list)->tail = (*list)->tail->previous;
    (*list)->tail->next = NULL;
    free(temp);
    return;
}


void deleteFromPos(List**list, int pos)
{
    if((*list)->head == NULL)
    {
        printf("The List Is Empty\n");
        return;
    }

    int len = length(*list);

    if(pos < 1 || pos > len)
    {
        printf("Bad Location\n");
        return;
    }

    else if(pos == 1)
    {
        deleteFirst(list);
        return;
    }

    else if(pos == len)
    {
        deleteLast(list);
        return;
    }
   

    int i = 1;
    Node*temp = (*list)->head;
    while (i < pos)
    {
        temp = temp->next;
        i++;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    free(temp);

    return;
 
}


void display(List* list)
{
    if(list->head == NULL)
        return;
    Node*temp = list->head;
    while (temp)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
    
}



int main(void) {
    List *list = (List*) malloc (sizeof(List));
    list->head = list->tail = NULL;

    push(&list,40);
    push(&list,50);
    push(&list,60);
    insertFirst(&list,30);
    insertFirst(&list,20);
    insertFirst(&list,10);
    insertAtPos(&list,6,18);
    insertAfterPos(&list,2,19);
    deleteFirst(&list);
    deleteLast(&list);
    deleteFromPos(&list, 6);
    display(list);

    printf("\nlength is %d", length(list));

    return 0;
}
