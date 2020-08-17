//funtion to calculate minimum depth of binary tree

int minDepth(Node *node) {
    // Your code here
    if(node==NULL)
    {
        return 0;
    }
    if(node->left==NULL&&node->right==NULL)
    return 1;
    
    if(node->left==NULL)
    return 1+minDepth(node->right);
    
    if(node->right==NULL)
    return 1+minDepth(node->left);
    
    return 1+min(minDepth(node->left),minDepth(node->right));
}
