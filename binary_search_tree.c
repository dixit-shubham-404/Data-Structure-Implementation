#include<stdio.h>
#include<stdlib.h>

//defining node
struct node{
	int key;
	struct node *left,*right;
};

//function to create new node
struct node * new_node(int item)
{
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->key=item;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}

//function to insert node in BST
struct node * insert(struct node *node,int item)
{
    if(node==NULL)
        return new_node(item);
    if(item < node->key)
        node->left=insert(node->left,item);
    else if(item > node->key)
        node->right=insert(node->right,item);

    return node;
}


//function to print inorder traversal of BST
void inorder(struct node * node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d ",node->key);
        inorder(node->right);
    }

}

struct node *min_value_node(struct node * node)
{
    struct node *current=node;
    while(current && current->left!=NULL)
        current=current->left;

    return current;

}

struct node *delete_node(struct node*root,int item)
{
    if(root==NULL)
        return root;

    if(item < root->key)
        root->left=delete_node(root->left,item);
    else if(item > root->key)
        root->right=delete_node(root->right,item);
    else{
        if(root->left==NULL)
        {
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=min_value_node(root->right);

        root->key=temp->key;
        root->right=delete_node(root->right,temp->key);

    }
    return root;
}

struct node * search(struct node* root,int item)
{
    if(root==NULL || root->key==item)
        return root;

    if(root->key > item)
        return search(root->left,item);

    if(root->key < item)
        return search(root->right,item);
}

int main()
{

	struct node *root = NULL;
	int n=0;
    printf("===============BINARY SEARCH TREE IMPLEMENTATION=============\n\n");
	while(1)
    {
        printf("-> Press 1 to print inorder traversal of tree\n");
        printf("-> Press 2 to search for the node in tree\n");
        printf("-> Press 3 to insert a node in tree\n");
        printf("-> Press 4 to delete node in tree\n");
        printf("-> Press 0 to exit\n");
        printf("Enter HERE\n========\n");
        scanf("%d",&n);
        printf("\n=======\n");
        if(n==1)
        {
            printf("The inorder traversal is : ");
            inorder(root);
            printf("\n===========================================\n");
        }
        if(n==2)
        {
            int item;
            printf("Enter key value to be searched: ");
            scanf("%d",&item);
            struct node *temp=search(root,item);
            if(temp==NULL)
            {
                printf("\n Node is not present");
                printf("\n===========================================\n");
            }
            else{
                printf("\n Node is present");
                printf("\n===========================================\n");
            }
        }
        if(n==3)
        {
            int item;
            printf("Enter the key value to be inserted: ");
            scanf("%d",&item);
            if(root==NULL)
                root=insert(root,item);
            else
                insert(root,item);
            printf("\n===========================================\n");
        }
        if(n==4)
        {
            int item;
            printf("Enter the key value to be deleted: ");
            scanf("%d",&item);
            delete_node(root,item);
            printf("\n===========================================\n");
        }
    }

	return 0;
}
