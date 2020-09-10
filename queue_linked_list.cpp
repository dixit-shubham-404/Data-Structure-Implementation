//Queue Implementation Linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node * next;
};

void enqueue(Node **front,Node **rear,int data)
{
	struct Node *new_node=(struct Node*)malloc(sizeof(struct node*));
	new_node->data=data;
	new_node->next=NULL;
	if(*front==NULL)
		*front=new_node;
	*rear=new_node;
}

void dequeue(Node **front,Node **rear)
{
	if(*rear==NULL)
		return;
	if(*front==*rear)
	{
		*front=*rear=NULL;
	}
	
	struct Node* temp=*front;
	
	*front=(*front)->next;
	
	free(temp);
	
}



int main()
{
	Node *rear=NULL,*front=NULL;
	enqueue(&front,&rear,1);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	enqueue(&front,&rear,22);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	enqueue(&front,&rear,33);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	enqueue(&front,&rear,44);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	enqueue(&front,&rear,55);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	dequeue(&front,&rear);
	cout<<"Front:"<<front->data<<" Rear:"<<rear->data<<endl;
	
}