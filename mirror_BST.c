//function to mirror a BST

void mirror(Node * node)
{
	if(node)
	{	
		mirror(node->left);
		mirror(node->right);
		Node *temp=node->right;
		node->right=node->left;
		node->left=temp;
	}
}