#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
   int value;
   struct node *next;  
} Node;

typedef struct  linked_list
{
    Node*head;
    Node*tail;

}LinkedList;


int length(LinkedList*list)
{
    if(list->head == NULL)
    return 0;
    
    Node* temp = list->head;
    int count = 0;
    while(temp)
    {
        temp = temp->next;
        count++;
    }
    return count;
}
//to make pushing O(1)
void push(LinkedList**list, int val)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value  = val;

    if((*list)->head == NULL)
    {
        (*list)->head = newNode;
        (*list)->tail = newNode;
        return;
    }

    (*list)->tail->next = newNode;
    (*list)->tail = newNode;

    
}

void display(LinkedList *list)
{
    if(list->head == NULL)
        return;
    Node* temp = list->head;
    while (temp)
    {
        printf("%d\t", temp->value);
        temp = temp->next;
    }
    
    
}


int main(void) {
//   Node* head = NULL;
//   Node*temp = NULL;
//   int choice;
//   printf("Do you want to continue?\n");
//   scanf("%d", &choice);

//   while (choice)
//   {
//     Node* newNode = (Node*) malloc(sizeof(Node));
//     printf("Enter The number:\n");
//     scanf("%d", &newNode->value);
//     newNode->next = NULL;
//     if(head == NULL)
//         head = temp = newNode;
//     else
//     {
//         temp->next = newNode;
//         temp = newNode;
//     }
//     printf("Do you want to continue?\n");
//     scanf("%d", &choice);
//   }
//   temp = head;
//   while (temp)
//   {
//    printf("%d\t", temp->value);
//    temp = temp->next;
//   }
  
    LinkedList *list ;
    list->head = NULL;
    list->tail = NULL;

    push(&list,10);
    push(&list,100);
    push(&list,1000);
    push(&list,10000);
    push(&list,100000);

    display(list);
        
    return 0;
}
