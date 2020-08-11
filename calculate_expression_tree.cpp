//Calculate the value of expresion tree

int evalTree(node* root) {
    // Your code here
    string s1="+",s2="-",s3="*",s4="/";
       if(!root->data.compare(s1))
       {
           int left=evalTree(root->left);
           int right=evalTree(root->right);
           return left+right;
       }
       else if(!root->data.compare(s2))
       {
           int left=evalTree(root->left);
           int right=evalTree(root->right);
           return left-right;
       }
       else if(!root->data.compare(s3))
       {
           int left=evalTree(root->left);
           int right=evalTree(root->right);
           return left*right;
       }
       else if(!root->data.compare(s4))
       {
           int left=evalTree(root->left);
           int right=evalTree(root->right);
           return left/right;
       }
        else
        {
            stringstream convert(root->data);
            int x=0;
            convert>>x;
            return x;
        }
}
