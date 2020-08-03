//MergeSort for linked list

#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node *next;
};

void push(Node **head,int data)
{
	Node *temp=new Node();
	temp->data=data;
	temp->next=*head;
	*head=temp;
}

void print_list(Node *head)
{
	while(head!=NULL)
	{
		cout<<head->data<<" -> ";
		head=head->next;
	}
}

void split(Node *root,Node **a,Node **b)
{
	Node *low=root,*high=root->next;
	//cout<<low->data<<" "<<high->next<<endl;
	while(high!=NULL)
	{
		high=high->next;
		//cout<<"reach"<<high<<endl;
		if(high!=NULL)
		{
			high=high->next;
			low=low->next;
		}
	}
	
	*a=root;
	*b=low->next;
	low->next=NULL;
}

Node* Merge(Node *a,Node *b)
{
	Node *result=NULL;
	if(a==NULL)
		return b;
	if(b==NULL)
		return a;
	
	if(a->data < b->data)
	{
		result=a;
		result->next=Merge(a->next,b);
	}
	else
	{
		result=b;
		result->next=Merge(a,b->next);
	}
	return result;
}

void MergeSort(Node **head)
{
	Node *node=*head;
	//cout<<node->next<<endl;
	if(node!=NULL && node->next!=NULL)
	{
		//cout<<"Inside If for "<<node->data<<endl;
		
		Node *a,*b;
		split(node,&a,&b);
		//cout<<"Done1"<<endl;
		//cout<<a->data<<" "<<b->data<<" "<<a->next<<" "<<b->next<<endl;
		MergeSort(&a);
		//cout<<"Done2"<<endl;
		MergeSort(&b);
		
		*head=Merge(a,b);
	}
}


int main()
{
	Node *head=NULL;
	push(&head,25);
	push(&head,45);
	push(&head,35);
	push(&head,45);
	push(&head,45);
	push(&head,100);
	push(&head,4);
	push(&head,4);
	push(&head,0);
	MergeSort(&head);
	
	print_list(head);
}