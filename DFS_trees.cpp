//funtion to implement DFS for trees

void DFS(node *root)
{
	if(root==NULL)
		return;
	stack<node *> s;
	s.push(root);
	while(s.size()!=0)
	{
		node *temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		if(temp->right)
			s.push(temp->right);
		if(temp->left)
			s.push(temp->left);
	}
}