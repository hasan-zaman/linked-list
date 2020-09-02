#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail, *temp;

void createCLL()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;

    if(tail==0){
        tail=newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
}

void insertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));

    printf("Enter Data ");
    scanf("%d", &newnode->data);
    newnode->next=0;

    if(tail==0){
        tail = newnode;
        tail->next = newnode;
    }
    else{
        newnode->next = tail->next;
        tail->next = newnode;
    }
}

void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->next = tail->next;
    tail->next = newnode;
    tail = newnode;
}

int getLength()
{
    int count=0;

    temp = tail->next;
    while(temp->next != tail->next)
    {
        count++;
        temp = temp->next;
    }
    return count+1;
}

void insertAtPosition()
{
    int i=1, position;
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(newnode));

    printf("Enter Position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || position> l+1){
        printf("INVALID POSITION");
    }
    else if(position == 1){
        insertAtBeginning();
    }
    else if(position == l+1){
        insertAtEnd();
    }
    else{
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf("%d", &newnode->data);
        newnode->next=0;

        temp = tail->next;
        while(i<position-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}

void deleteFromBeginning()
{
    temp = tail->next;
    if(tail==0){
        printf("LIST IS EMPTY!!!\N");
    }
    else if(temp->next==temp){
        tail=0;
        free(temp);
    }
    else{
        tail->next = temp->next;
        free(temp);
    }
}

void deleteFromEnd()
{
    struct node *current, *previous;
    current = tail->next;

    if(tail==0){
        printf("LIST IS EMPTY\n");
    }
    else if(current->next == current){
        tail = 0;
        free(current);
    }
    else{
        while(current->next != tail->next){
            previous = current;
            current = current->next;
        }
        previous->next = current->next;
        tail = previous;
        free(current);
    }
}

void deleteFromPosition()
{
    struct node *current, *previous;
    int position, i=1;

    printf("Enter Position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || position>l){
        printf("INVALID POSITION!!!\n");
    }
    else if(position==1){
        deleteFromBeginning();
    }
    else if(position==l){
        deleteFromEnd();
    }
    else{
        current = tail->next;
        while(i<position){
            previous = current;
            current = current->next;
            i++;
        }
        previous->next = current->next;

        free(current);
    }
}

void reverse()
{
    struct node *current, *prev, *nextnode;

    current = tail->next;
    nextnode = current->next;

    if(tail == 0){
        printf("LIST IS EMPTY!!!\n");
    }
    while(current != tail)
    {
        prev = current;
        current = nextnode;
        nextnode = current->next;
        current->next = prev;
    }
    nextnode->next = tail;
    tail = nextnode;
}

void display()
{
   if(tail==0)
   {
       printf("LIST is EMPTY\n");
   }
   else{
    temp = tail->next;
   }

   while(temp->next != tail->next)
   {
       printf("%d ", temp->data);
       temp = temp->next;
   }
   printf("%d\n", temp->data);
}

void main()
{
    int ch;


    do{
        printf("ENTER CHOICE\n 1.Create Node\n 2.Display\n 3.Insert At Beginning\n 4.Insert At END\n 5.Insert At Position\n 6.Delete From Beginning\n 7.Delete From END\n 8.Delete From given Position\n 9.Reverse\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1: createCLL();
                    break;
            case 2: display();
                    break;
            case 3: insertAtBeginning();
                    break;
            case 4: insertAtEnd();
                    break;
            case 5: insertAtPosition();
                    break;
            case 6: deleteFromBeginning();
                    break;
            case 7: deleteFromEnd();
                    break;
           case 8: deleteFromPosition();
                    break;
            case 9: reverse();
                    break;


            default: printf("INVALID CHOICE");
        }
    }while(ch!=0);
}
