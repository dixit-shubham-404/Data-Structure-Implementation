//A funtion to implement BFS on trees

struct Node{
	int data;
	Node *left,*right;
};

void BFS(Node *root)
{
	if(root==NULL)
		return;
	queue<Node *> q;
	q.push(root);
	while(q.size()!=0)
	{
		struct Node *temp=q.front();
		q.pop();
		cout<<temp->data<<" ";
		if(temp->left)
			q.push(temp->left);
		if(temp->right)
			q.push(temp->right);
	}
}