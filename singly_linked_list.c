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
    newNode->next  = NULL;
    newNode->value = val;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    Node*temp = *head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return; 
    
}

void insertFirst(Node** head, int val)
{
    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->next  = NULL;
    newNode->value = val;

    if(*head == NULL)
    {
        *head = newNode;
        return;
    }

    newNode->next = *head;
    *head = newNode;
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

void insertAfter(Node** head, int val,int pos)
{
    if(!length(*head))
    {
        push(head, val);
        return;
    }
    
    if(pos < 1 || pos > length(*head))
    {
        printf("Wrong Position\n");
        return;
    }

    Node *newNode  = (Node*) malloc (sizeof(Node));
    newNode->next  = NULL;
    newNode->value = val;
    Node*temp = *head;
    
    int i;
    for(i = 1; i < pos; i++)
    {
        temp = temp->next;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    
      
    return;
}


void display(Node* head)
{
    if(head == NULL)
        return;
    Node*temp = head;
    while (temp)
    {
        printf("%d\n", temp->value);
        temp = temp->next;
    }
    
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

// void deleteLastNode(Node** head)
// {
//     if(*head == NULL)
//     {
//         printf("Empty List!\n");
//         return ;
//     }

//     else if((*head)->next == NULL)
//     {
//         free(*head);
//         *head = NULL;
//         return;
//     }

//     Node *temp, *previous;
//     temp = *head;
//     while (temp->next)
//     {
//         previous = temp;
//         temp = temp->next;
//     }
    
//     free(temp);
//     previous->next = NULL;
//     return;

// }

//another implementaion without previous pointer
void deleteLastNode(Node** head)
{
    if(*head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }

    else if((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }

    Node *temp;
    temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;

    return;

}

void deleteNodeWithPosition(Node ** head, int pos)
{
        if(*head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }
    if(pos == 1)
    {
        deleteFirstNode(head);
        return;
    }
    if(pos < 1 || pos > length(*head) )
    {
        printf("Wrong Position\n");
        return;
    }

    Node*temp = *head;
    Node*del;
    int idx = 1;

    while(idx < pos-1)
    {
        temp = temp->next;
        idx++;
    }
    
    del = temp->next;
    temp->next = del->next;
    free(del);
    return;

}

void reverseList(Node ** head)
{
    if(*head == NULL || (*head)->next == NULL)
        return;
    Node*prevNode,*curr,*nextNode;
    curr = nextNode = *head;
    prevNode = NULL;
    while (nextNode)
    {
        nextNode   = nextNode->next;
        curr->next = prevNode;
        prevNode = curr;
        curr = nextNode;
    }

    *head = prevNode;
    

}

void displayReversedListRecursive(Node *head)
{
    if(head == NULL || head->next == NULL)
    {
        return;
    }
    displayReversedListRecursive(head->next);
    printf("%d\t", head->value);
}


void reverseListRecursive(Node **head)
{
       if(head == NULL || (*head)->next == NULL)
    {
        return;
    }

    Node*rest = (*head)->next;
    reverseListRecursive(&rest);
    (*head)->next->next = *head;
    (*head)->next = NULL;
    
    *head = rest;

}

int main(void) {

        Node* head = NULL;
        push(&head,10);
        push(&head,20);
        push(&head,30);
        push(&head,40);
        push(&head,50);
        reverseList(&head);
        display(head);
        printf("\nlength is %d\n",length(head));

    return 0;
}
