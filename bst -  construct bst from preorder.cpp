#include<bits/stdc++.h>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
};
Node* newNode(int data)
{
    Node* temp = new Node();
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
void inorder(Node* root)
{
   if(root==NULL)return;
   
   inorder(root->left);
   cout<<root->data<<" ";
   inorder(root->right);
}
Node* find(int a[],int* preindex,int key,int min,int max,int n)
{
	if(*preindex >= n)return NULL;
	
	Node* root = NULL;
	
	if(key > min && key < max)
	{
		root = newNode(key);
		*preindex = *preindex+1;
		
		if(*preindex < n)
		{
			root->left = find(a,preindex,a[*preindex],min,key,n);
		}
		if(*preindex < n)
		{
			root->right = find(a,preindex,a[*preindex],key,max,n);
		}
	}
	return root;
}
Node* construct(int a[],int n)
{
	int pre = 0;
	return find(a,&pre,a[0],INT_MIN,INT_MAX,n);
}
int main()
{
	int n;
	cin >>n;
	int a[n];
	for(int i=0;i<n;i++)cin >>a[i];
    Node* root = construct(a,n);
    inorder(root);
}
