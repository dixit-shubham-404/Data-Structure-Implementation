//function that takes root of B-Tree and print the boundary nodes


void printLeft(Node *node)
{
	if(node==NULL)
		return;
	
	if(node->left!=NULL)
	{
	cout<<node->data<<" ";
	printLeft(node->left);
	}
	else if(node->right!=NULL)
	{
		cout<<node->data<<" ";
		printLeft(node->right);
	}
}

void printRight(Node * node)
{
	if(node==NULL)
		return;
	if(node->right!=NULL)
	{
		printRight(node->right);
		cout<<node->data<<" ";
		
	}
	else if(node->left!=NULL)
	{
		printRight(node->left);
		cout<<node->data<<" ";
		
	}
}

void printLeaves(Node *node)
{
	if(node==NULL)
		return;
	
	printLeaves(node->left);
	
	if(node->left==NULL && node->right==NULL)
		cout<<node->data<<" ";
	
	printLeaves(node->right);
}

void boundary(Node *root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	
	printLeft(root->left);
	
	printLeaves(root->left);
	printLeaves(root->right);
	
	printRight(root->right);
}