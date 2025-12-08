#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;  
} Node;

Node *head = NULL;
Node *tail = NULL;


/* -------------------- Utility Functions -------------------- */

int length()
{
    if (head == NULL)
        return 0;

    int count = 0;
    Node* temp = head;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void display()
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

void displayWithTail()
{
    if(tail == NULL)
        return;
    Node *temp = tail->next;
    do
    {
        printf("The Value Is %d\n", temp->value);
        temp = temp->next;
    } while (temp != tail->next);
}


/* -------------------- Insertion Functions -------------------- */

void push(int val)
{
    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->value = val;

    if(head == NULL)
    {
        newNode->next = newNode;
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void pushWithTail(int val)
{
    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->value = val;

    if(tail == NULL)
    {
        newNode->next = newNode;
        tail = newNode;
        return;
    }
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertFirst(int val)
{
    if(head == NULL)
    {
        push(val);
        return;
    }
    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = head;
    head = newNode;
    tail->next = head;
}

void insertFirstWithTail(int val)
{
    if(tail == NULL)
    {
        pushWithTail(val);
        return;
    }
    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = tail->next;
    tail->next = newNode;
    head = newNode; // keep head consistent
}

/*
    Inserts a new node at the given position in a circular linked list (tail-based).
    - If the list is empty or position == len + 1 → append using pushWithTail().
    - If position == 1 → insert at the beginning using insertFirstWithTail().
    - Otherwise → insert in the middle.
    Note: Positions are 1-indexed.
*/
void insertAtPosWithTail(int val, int pos)
{
    int len = length();
    if(tail == NULL || pos == len+1)
    {
        pushWithTail(val);
        return;
    }
    else if (pos == 1)
    {
        insertFirstWithTail(val);
        return;
    }
    else if (pos<1 || pos>len)
        return;

    int i = 1;
    Node*temp = tail->next;
    while (i<pos-1)
    {
        temp = temp->next;
        i++;
    }

    Node* newNode  = (Node*) malloc(sizeof(Node));
    newNode->value = val;
    newNode->next  = temp->next;
    temp->next     = newNode;
}


/* -------------------- Deletion Functions -------------------- */

void deleteFirstNode()
{
    if(head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }
    
    int len = length();
    if (len == 1)
    {
        free(head);
        head = tail = NULL;
        return;
    }
     
    Node* temp = head;
    head = head->next;
    tail->next = head;
    free(temp);
}

void deleteFirstNodeWithTail()
{
    if(tail == NULL)
        return;
    else if(tail->next == tail)
    {
        free(tail);
        tail = head = NULL;
        return;
    }
    Node*temp = tail->next;
    tail->next = temp->next;
    head = tail->next;
    free(temp);
}

void deleteLastNode()
{
    if(head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }
    
    else if (head->next == head)
    {
        deleteFirstNode();
        return;
    }

    Node*temp = head;
    Node*prev = NULL;
    while (temp->next != head)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = head;
    tail = prev;
    free(temp);
       
}

void deleteLastNodeWithTail()
{
    if(tail == NULL)
        return;

    else if(tail->next == tail)
    {
        deleteFirstNodeWithTail(); 
        return;
    }

    Node*temp_head = tail->next;
    Node*prev = NULL;
    while (temp_head->next != tail->next)
    {
        prev = temp_head;
        temp_head = temp_head->next;
    }

    prev->next = temp_head->next;
    tail = prev;
    free(temp_head);
    
}

void deleteFromPos(int pos)
{
    int len = length();

    if (pos > len || pos < 1)
    {
        printf("Invalid position!\n");
        return;
    }
    if(head == NULL)
    {
        printf("Empty List!\n");
        return ;
    }
    
    else if ((head->next == head) || pos == 1)
    {
        deleteFirstNode();
        return;
    }

    else if(pos == len)
    {
        deleteLastNode();
        return;
    }

    Node* temp = head;
    Node*toDelete ;
    int i = 1;
    while(i < pos-1 && temp->next != head )
    {
        temp = temp->next;
        i++;
    }
    toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete); 
    
}

void deleteFromPosWithTail(int pos)
{
    int len = length();

    if(pos < 1 || pos > len)
    {
        printf("invalid position\n");
        return;
    }

    else if (tail == NULL)
    {
    
        printf("Empty List!\n");
        return ;

    }

    else if (tail->next == tail)
    {
        deleteFirstNodeWithTail();
        return;
    }

    else if (pos == 1)
    {
        deleteFirstNodeWithTail();
        return;
    }
    else if(pos == len)
    {
        deleteLastNodeWithTail();
        return;
    }

    int i = 1;
    Node* temp = tail->next;
    Node* toDelete = NULL;

    while (i < pos-1 && temp->next != tail->next)
    {
       temp = temp->next;
       i++;
    }

    toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete); 
    

}

/* -------------------- Main Function -------------------- */

int main(void)
{
    push(10);
    push(20);
    push(30);
    push(40);
    insertFirst(5);
    pushWithTail(50);
    insertAtPosWithTail(1,2);
    insertAtPosWithTail(3,4);
    insertAtPosWithTail(33,8);
    deleteFirstNodeWithTail();
    deleteLastNode();
    deleteLastNodeWithTail();
    deleteLastNodeWithTail();
    deleteFromPos(3);
    deleteFromPosWithTail(3);
    display();
    
    // printf("\n\nThe Length Of List Is %d\n",length());
    // printf("\nValue Of Head Node Is %d By Tail Node\n",tail->next->value);
    // displayWithTail();
    return 0;
}
