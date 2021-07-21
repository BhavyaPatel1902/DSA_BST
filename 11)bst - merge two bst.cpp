#include<bits/stdc++.h>
using namespace std;
class Node 
{ 
    public:
    int data; 
    Node* left; 
    Node* right; 
};
Node* newNode(int data) 
{ 
    Node* node = new Node();
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
 
    return(node); 
} 
 
// A utility function to print inorder
// traversal of a given binary tree 
void printInorder(Node* node) 
{ 
    if (node == NULL) 
        return; 
 
    /* first recur on left child */
    printInorder(node->left); 
 
    cout << node->data << " "; 
 
    /* now recur on right child */
    printInorder(node->right); 
} 
void storeinorder(Node* root,int a[],int *i)
{
	if(root==NULL)return;
	
	storeinorder(root->left,a,i);
	
	a[*i] = root->data;
	(*i)++;
	
	storeinorder(root->right,a,i);
}
int *merge(int a[],int b[],int n,int m)
{
	int *merged = new int[m+n];
	
	int i=0,j=0,k=0;
	
	while(i<m&&j<n)
	{
		if(a[i]<b[j])
		{
			merged[k] = a[i];
			i++;
		}
		else
		{
			merged[k] = b[j];
			j++;
		}
		k++;
	}
	
	while(i<m)
	{
		merged[k++] = a[i++];
	}
	while(j<n)
	{
		merged[k++] = b[j++];
	}
	
	return merged;
	
}
Node* sortedTObst(int a[],int st,int end)
{
	if(st>end)return NULL;
	
	int mid  = (st+end)/2;
	
	Node* root = newNode(a[mid]);
	
	root->left = sortedTObst(a,st,mid-1);
	
	root->right = sortedTObst(a,mid+1,end);
	
	return root;
}
Node* mergeTrees(Node* root1,Node* root2,int m,int n)
{
	int a[m];
	int i = 0;
	storeinorder(root1,a,&i);
	
	
	int b[n];
	int j=0;
	storeinorder(root2,b,&j);
	
	int *merged = merge(a,b,n,m);
	
	return sortedTObst(merged,0,m+n-1);
}
int main()
{
	Node *root1 = newNode(100); 
    root1->left     = newNode(50); 
    root1->right = newNode(300); 
    root1->left->left = newNode(20); 
    root1->left->right = newNode(70); 
 
    /* Create following tree as second balanced BST 
            80 
        / \ 
        40 120 
    */
    Node *root2 = newNode(80); 
    root2->left     = newNode(40); 
    root2->right = newNode(120); 
 
    Node *mergedTree = mergeTrees(root1, root2, 5, 3); 
 
    cout << "Following is Inorder traversal of the merged tree \n"; 
    printInorder(mergedTree); 
 
    return 0; 
}
