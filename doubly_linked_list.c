#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head, *newnode, *temp, *tail;


void create()
{
    //head=0;
    //struct node *temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    if(head==0)
    {
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev = temp;
        temp = newnode;
    }
}

void createDLL()
{
    struct node *newnode;
    newnode= (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    if(head==0){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
}

void insertAtBeginning()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->prev=0;
    newnode->next=0;

    head->prev = newnode;
    newnode->next = head;
    head = newnode;
}

void insertAtEnd()
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));

    printf("Enter Data ");
    scanf("%d", &newnode->data);

    newnode->next=0;

    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

int getLength()
{
    int count=0;

    temp=head;
    while(temp!=0){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtPosition()
{
    int position,i=1;
    printf("Enter position ");
    scanf("%d", &position);

    int l = getLength();

    if(position<1 || (position>(l+1))){
        printf("INVALID POSITION!!!");
    }
    else if(position==1){
        insertAtBeginning();
    }
    else if(position==(l+1)){
        insertAtEnd();
    }
    else{
        struct node *newnode;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data ");
        scanf("%d", &newnode->data);

        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next = newnode;
        newnode->next->prev = newnode;
    }
}

void deleteFromBeginning()
{
    if(head==0){
        printf("LIST is EMPTY!");
    }
    else{
        temp=head;
        head = head->next;
        head->prev =0;
        free(temp);
    }
}

void deleteFromEnd()
{
    temp = tail;
    tail = temp->prev;
    tail->next = 0;
    free(temp);
}

void deleteFromPosition()
{
    int i=1, position;

    printf("Enter Position ");
    scanf("%d", &position);

    if(position>getLength()){
        printf("INVALID POSITION");
    }
    else if(position==1){
        deleteFromBeginning();
    }
    else if(position==getLength()){
        deleteFromEnd();
    }
    else{
        temp=head;
        while(i<position){
            temp = temp->next;
            i++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        free(temp);
    }
}

void reverse()
{
    struct node *currentnode, *nextnode;

    currentnode=head;

    while(currentnode!=0){
        nextnode=currentnode->next;
        currentnode->next = currentnode->prev;
        currentnode->prev = nextnode;
        currentnode = nextnode;
    }
    currentnode = head;
    head = tail;
    tail = currentnode;
}

void display()
{
    struct node *temp;
    temp=head;
    while(temp!=0)
    {
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void main()
{
    int ch;

    do{
        printf("Enter Choice: 1/2-Create NODE \n 3- Display\n 4- Insert At Beginning\n 5-Insert At End\n 6-Insert At Given Position\n 7-Delete From Beginning\n 8-Delete from End\n 9-Delete from Specific Position\n 10-REVERSE 0-To exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: create();
                    break;
            case 2: createDLL();
                    break;
            case 3: display();
                    break;
            case 4: insertAtBeginning();
                    break;
            case 5: insertAtEnd();
                    break;
            case 6: insertAtPosition();
                    break;
            case 7: deleteFromBeginning();
                    break;
            case 8: deleteFromEnd();
                    break;
            case 9: deleteFromPosition();
                    break;
            case 10: reverse();
                     break;


            default: printf("INVALID CHOICE");
        }
    }while(ch!=0);
}
