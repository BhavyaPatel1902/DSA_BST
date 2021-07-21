#include<bits/stdc++.h>
using namespace std;
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
      
    /* Constructor that allocates  
    a new node with the given data  
    and NULL left and right pointers. */
    node(int data) 
    { 
        this->data = data; 
        this->left = NULL; 
        this->right = NULL; 
          
    } 
}; 
int find(node* root,int *max_ref,int *min_ref,int *max_size,int *isbst)
{
	if(root==NULL)
	{
		*isbst = 1;
		return 0;
	}
	
	int mini = INT_MAX;
	
	bool left = false;
	bool right = false;
	
	int ls,rs;
	
	
	*max_ref = INT_MIN;
	
	ls = find(root->left,max_ref,min_ref,max_size,isbst);
	
	if(*isbst==1&&root->data>*max_ref)left = true;
	
	
	mini = *min_ref;
	
	*min_ref = INT_MAX;
	
	rs = find(root->right,max_ref,min_ref,max_size,isbst);
	
	if(*isbst==1&&root->data<*min_ref)right = true;
	
	if(mini<*min_ref)*min_ref = mini;
	
	if(root->data < *min_ref) *min_ref = root->data;
	
	if(root->data > *max_ref) *max_ref = root->data;
	
	
	if(left&&right)
	{
		if(ls+rs+1>*max_size)
		{
			*max_size = ls+rs+1;
		}
		return (ls+rs+1);
	}
	else
	{
		*isbst = 0;
		return 0;
	}
	
}
int largestBST(node* root)
{
	int mini = INT_MAX;
	int maxi = INT_MIN;
	
	int max_size = 0;
	int isbst = 0;
	
	find(root,&maxi,&mini,&max_size,&isbst);
	
	return max_size;
}
int main()
{
	node *root = new node(50);  
    root->left = new node(10);  
    root->right = new node(60);  
    root->left->left = new node(5);  
    root->left->right = new node(20);  
    root->right->left = new node(55);  
    root->right->left->left = new node(45);  
    root->right->right = new node(70);  
    root->right->right->left = new node(65);  
    root->right->right->right = new node(80);  
      
    /* The complete tree is not BST  
    as 45 is in right subtree of 50.  
    The following subtree is the largest BST  
            60  
        / \  
        55 70  
    / / \  
    45 65 80  
    */
    cout<<" Size of the largest BST is "<< largestBST(root);  
  
    return 0; 
}
