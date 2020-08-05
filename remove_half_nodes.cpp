//funtion to remove half nodes of a binary tree

Node *RemoveHalfNodes(Node *node)
{
   //add code here.
   if(node==NULL)
   {
       return NULL;
   }
    node->left=RemoveHalfNodes(node->left);
    node->right=RemoveHalfNodes(node->right);
   
   if(node->left==NULL && node->right!=NULL)
   {
       return node->right;
   }
   if(node->left!=NULL && node->right==NULL)
   {
       return node->left;
   }
   
   return node;
}