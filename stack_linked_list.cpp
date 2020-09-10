//Stack Implementation using linked list

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	Node *next;
};

void push(struct Node **top,int data)
{
	struct Node *new_node = (struct Node*)malloc(sizeof(struct Node*));
	new_node->data=data;
	new_node->next=*top;
	*top=new_node;
}

void pop(struct Node **href)
{
	struct Node *temp=*href;
	*href=(*href)->next;
	cout<<"Poped :"<<temp->data<<endl;
	free(temp);
	
}

void display(Node *top)
{
	while(top!=NULL)
	{
		cout<<top->data<<"->";
		top=top->next;
	}
	cout<<endl;
}

int main()
{
	Node *top=NULL;
	push(&top,1);
	push(&top,2);
	push(&top,3);
	push(&top,4);
	display(top);
	pop(&top);
	display(top);
}