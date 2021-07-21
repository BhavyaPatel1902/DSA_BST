#include<bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node* left; 
    struct Node* right; 
};
struct Node* newNode(int data) 
{ 
    struct Node* temp = new struct Node; 
    temp->data = data; 
    temp->left = NULL; 
    temp->right = NULL; 
    return temp; 
} 
void inorderinsert(Node* root,vector <int> &v)
{
	if(root==NULL)return;
	inorderinsert(root->left,v);
	root->data = v.back();
	v.pop_back();
	inorderinsert(root->right,v);
}
void inorder(Node* root,vector <int> &v)
{
	if(root==NULL)return;
	inorder(root->left,v);
	v.push_back(root->data);
	inorder(root->right,v);
}
Node* binaryTreeToBST(Node* root)
{
	vector <int> v;
	inorder(root,v);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	inorderinsert(root,v);
	
	return root;
}
void printInorder(Node* root)
{
	if(root==NULL)return;
	printInorder(root->left);
	cout<<root->data<<" ";
	printInorder(root->right);
}
int main()
{
    struct Node* root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /      \ 
      20       5   */
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
  
    // convert Binary Tree to BST 
    root = binaryTreeToBST(root); 
  
    printf("Following is Inorder Traversal of the converted BST: \n"); 
    printInorder(root); 
  
    return 0; 	
}
