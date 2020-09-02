#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head, *newnode, *temp;

void createnode()
{
        newnode = (struct node*)malloc(sizeof(struct node));

        printf("Enter Data ");
        scanf("%d", &newnode->data);

        newnode->next=0;

        if(head==0){
            head=temp=newnode;
        }
        else{
            temp->next=newnode;
            temp = newnode;
        }
}

void display()
{
    temp=head;
    while(temp!=0){
        printf("%d ", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertAtBeginning()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data at Beginning ");
    scanf("%d", &newnode->data);

    newnode->next = head;
    head = newnode;
}

void insertAtEnd()
{
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Insert data at END ");
    scanf("%d", &newnode->data);
    newnode->next=0;

    temp = head;
    while(temp->next!=0)
    {
        temp = temp->next;
    }
    temp->next=newnode;
}

int getLength()
{
    temp=head;
    int count=0;

    while(temp!=0){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAfterGivenPosition()
{
    int position, i=1;
    printf("Enter position: ");
    scanf("%d", &position);

    if(position>getLength()){
        printf("INVALID POSITION");
    }
    else{
        temp=head;
        while(i<position-1){
            temp=temp->next;
            i++;
        }
    }
    newnode = (struct node *)malloc(sizeof(struct node));
     printf("Enter Data: ");
     scanf("%d", &newnode->data);
     newnode->next = temp->next;
     temp->next = newnode;
}

void DeleteFromBeginning()
{
    struct node *temp;
    temp=head;
    head= head->next;
    free(temp);
}

void DeleteFromEnd()
{
    struct node *prevnode;
    temp=head;

    while(temp->next!=0)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=0;
    }
    else{
        prevnode->next=0;
    }
    free(temp);
}

void DeleteFromPosition()
{
    struct node *nextnode;
    int position, i=1;

    printf("Enter Position ");
    scanf("%d", &position);

    if(position>getLength())
    {
        printf("INVALID POSITION!!!!!\n");
    }
    else if(position==1){
        DeleteFromBeginning();
    }
    else if(position==getLength()){
        DeleteFromEnd();
    }
    else{
    temp=head;
    while(i<position-1)
    {
        temp=temp->next;
        i++;
    }
    nextnode = temp->next;
    temp->next = nextnode->next;
    free(nextnode);
    }

}

void reverse()
{
    struct node *prevnode, *currentnode, *nextnode;
    prevnode=0;
    currentnode=nextnode=head;

    while(nextnode!=0)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}

void main()
{
    int ch=1;
    do
    {
        printf("Enter choice-\n 1- Create Node\n 2- Display\n 3- Insert At Beginning\n 4- Insert At End\n 5- Insert After Given Position\n 6-Delete From Beginning\n 7-Delete From End\n 8-Delete From Specific Position\n 9-Reverse\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: createnode();
                    break;
            case 2: display();
                    break;
            case 3: insertAtBeginning();
                    break;
            case 4: insertAtEnd();
                    break;
            case 5: insertAfterGivenPosition();
                    break;
            case 6: DeleteFromBeginning();
                    break;
            case 7: DeleteFromEnd();
                    break;
            case 8: DeleteFromPosition();
                    break;
            case 9: reverse();
                    break;

            default: printf("INVALID CHOICE!!!");
        }
    }
    while(ch!=0);

}
