/*
This is command line program to to insert and delete nodes in a linked list.
Insertion is done at the beginning,end and after a given node
Deletion is performed on a given key.
*/

#include<stdio.h>
#include<stdlib.h>

//Node structure is declared
struct node{
    int data;
    struct node * next;//this will point to next node
};

//This function enters data at the start of of the linked list
void start(struct node ** href,int data)
{
    struct node * new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data= data;
    new_node->next = *href;
    *href = new_node;
}

//This function enters the data at the end of the list
void end(struct node **href,int data)
{


    if(*href==NULL)
    {
        start(&*href,data);
    }
    else{
            struct node * new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data= data;
            new_node->next=NULL;
            struct node * temp = NULL;
            temp = *href;
            printf("%d\n",temp->data);
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
    }
}

//This function insert the node in the middle
void middle(struct node **href,int after,int data)
{
    struct node * new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=data;
    struct node * temp = *href;
    while((temp->data!=after)&&(temp->next!=NULL))
    {
        temp=temp->next;
    }
    if((temp->data==after))
    {
        struct node * temp2 = temp->next;
        temp->next = new_node;
        new_node->next = temp2;

    }
    else if((temp->data!=after)&&(temp->next==NULL))
    {
        printf("the number you entered doest not exist\n");
    }
}

//function to delete node
void delnode(struct node **href,int data)
{
    struct node * temp=*href,*prev;
    if(temp->data==data&&temp!=NULL)
    {
        *href=temp->next;
        free(temp);
        return;
    }
    while(temp->data!=data&&temp!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
        return;
    prev->next=temp->next;
    free(temp);
}

//This function displays the linked list
void display(struct node * dis)
{
    while(dis!= NULL)
    {
        printf("%d->\t",dis->data);
        dis=dis->next;
    }
}


int main()
{
    struct node *head = NULL;
    printf("Learn How a Linked list work...!!!\n");
    MENU :
    printf("\n1. Press 1 to insert at the beginning of the linked list\n");
    printf("2. Press 2 to insert at the end of the linked list\n");
    printf("3. Press 3 to insert after some node of the linked list\n");
    printf("4. Press 4 to delete a node\n");
    printf("Press other to exit\n");
    int choice,n,a;
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("Enter the number to be inserted at the beginning\n");
        scanf("%d",&n);
        start(&head,n);
        display(head);
        goto MENU;
        break;
    case 2:
        printf("Enter the number to be inserted at the end\n");
        scanf("%d",&n);
        end(&head,n);
        display(head);
        goto MENU;
        break;
    case 3:
        printf("Enter the node after which you want to insert\n");
        scanf("%d",&a);
        printf("Enter the node to be inserted");
        scanf("%d",&n);
        middle(&head,a,n);
        display(head);
        goto MENU;
        break;
    case 4:
        printf("Enter the node to be deleted\n");
        scanf("%d",&n);
        delnode(&head,n);
        display(head);
        break;
    default:
        exit(0);
    }

}

