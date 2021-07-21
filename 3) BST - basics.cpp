#include<bits/stdc++.h>
using namespace std;
class Node
{
	public:
	 int data;
	 Node* right;
	 Node* left;
};
Node* newNode(int data)
{
	Node* temp = new Node();
	temp->data = data;
	temp->right = NULL;
	temp->left = NULL;
	
	return temp;
}
void inorder(Node* temp)
{
	if(temp==NULL)return;
	
	inorder(temp->left);
	cout<<temp->data<<" ";
	inorder(temp->right);
}
Node* LCA(Node *root, int n1, int n2)
{
   if(root==NULL)return NULL;
   
   if(n1<root->data&&n2<root->data)return LCA(root->left,n1,n2);
   else if(n1>root->data&&n2>root->data)return LCA(root->right,n1,n2);
   
   return root;
}
Node* insert(Node* root,int data)
{
	if(root==NULL)
	{
		root = newNode(data);
		return root;
	}
	if(data>root->data)
	{
		root->right = insert(root->right,data);
	}
	else
	{
		root->left = insert(root->left,data);
	}
	return root;
}
Node* search(Node* root,int key)
{
	if(root==NULL||root->data==key)return root;
	
	if(root->data<key)return search(root->right,key);
	
	return search(root->left,key);
}
int minValue(Node* root)
{ 
     if(root==NULL)return -1;
     
     while(root->left!=NULL)
     {
         root = root->left;
     }
     
     return root->data;
}
int maxValue(Node* root)
{ 
     if(root==NULL)return -1;
     
     while(root->right!=NULL)
     {
         root = root->right;
     }
     
     return root->data;
}
/*void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL)return;
    
    if(root->data==data)
    {
        if(root->left!=NULL)
        {
            Node* temp = root->left;
            while(temp->right!=NULL)
            {
               temp=temp->right;
            }
            pre = temp;
        }
        if(root->right!=NULL)
        {
            Node* temp = root->right;
            while(temp->left!=NULL)
            {
                temp = temp->left;
            }
            suc = temp;
        }
    }
    else if(root->key>key)
    {
        suc = root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre = root;
        findPreSuc(root->right,pre,suc,key);
    }
}
bool isbst(Node* root,Node* l,Node* r)
{
    if(root==NULL)return true;
    
    if(l!=NULL&&root->data<=l->data)return false;
    
    if(r!=NULL&&root->data>=r->data)return false;
    
    return isbst(root->left,l,root)&&isbst(root->right,root,r);
}
bool isBST(Node* root) 
{
    return isbst(root,NULL,NULL);
}*/
Node* minValue_1(Node* root)
{
    Node* current = root;
 
    while (current && current->left != NULL)
        current = current->left;

    return current;
}
 
Node* deleteNode(Node* root,int data)
{
	if(root==NULL)return root;
	
	if(data<root->data)root->left = deleteNode(root->left,data);	
	else if(data>root->data)root->right = deleteNode(root->right,data);
	else
	{
		if(root->left==NULL)
		{
			Node* temp1 = root->right;
			free(root->right);
			return temp1;
		}
		else if(root->right==NULL)
		{
			Node* temp1 = root->left;
			free(root->left);
			return temp1;
		}
		else
		{
			Node* temp1 = minValue_1(root->right);
			root->data = temp1->data;
			root->right = deleteNode(root->right,temp1->data);
		}
	}
	return root;
}
void kth_l(Node* root,int &ct,int k,int &ans)
{
    if(root==NULL||ct>=k)return; 
    
    kth_l(root->right,ct,k,ans);
    
    ct++;
    
    if(ct==k)
    {
        ans = root->data;
        return;
    }
    
    kth_l(root->left,ct,k,ans);
}
int kthLargest(Node *root, int K)
{
    int ct = 0;
    int ans = 0;
    
    kth_l(root,ct,K,ans);
    
    return ans;
}
void kth_s(Node* root,int &ct,int k,int &ans)
{
    if(root==NULL||ct>=k)return;
    
    kth_s(root->left,ct,k,ans);
    
    ct++;
    
    if(ct==k)
    {
        ans = root->data;
    }
    
    kth_s(root->right,ct,k,ans);
}
int KthSmallestElement(Node *root, int K)
{
    int ct = 0;
    int ans = -1;
    
    kth_s(root,ct,K,ans);
    
    return ans;
}
//count bst nodes in given range from l to h
int getCount(Node *root, int l, int h)
{
    if(root==NULL)return 0;
    
    if(root->data==l&&root->data==h)return 1;
    
    if(root->data<=h&&root->data>=l)
    {
        return 1+getCount(root->left,l,h)+getCount(root->right,l,h);
    }
    else if(root->data<l)
    {
        return getCount(root->right,l,h);
    }
    else
    {
        return getCount(root->left,l,h);
    }
}
//replace element in the array with least greater element on the right
void insert_1(Node* root,int data,Node*& succ)
{
	if(root==NULL)root = newNode(data);
	
	if(data<root->data)
	{
		succ = root;
		insert_1(root->left,data,succ);
	}
	else if(data>root->data)
	{
		insert_1(root->right,data,succ);
	}
}
void replace(int a[],int n)
{
	Node* root = NULL;
	
	for(int i=n-1;i>=0;i--)
	{
		Node* succ = NULL;
		
		insert_1(root,a[i],succ);
		
		if(succ)a[i] = succ->data;
		else a[i] = -1;	
	}
}
//check for dead end
void storeall(Node* root,unordered_set <int> &all,unordered_set <int> &leafs)
{
	if(root==NULL)return;
	
	all.insert(root->data);
	
	if(root->left==NULL&&root->right==NULL)
	{
	   leafs.insert(root->data);
	   return;
    }
    
    storeall(root->left,all,leafs);
    storeall(root->right,all,leafs);
}
bool deadend(Node* root)
{
	if(root==NULL)return false;
	
	unordered_set <int> all;
	unordered_set <int> leafs;
	
	all.insert(0);
	
	storeall(root,all,leafs);
	
	for(auto i = leafs.begin();i!=leafs.end();i++)
	{
		int x = (*i);
		
		if(all.find(x+1)!=all.end()&&all.find(x-1)!=all.end())return true;
	}
	return false;
}
//count pairs in 2 BSTs whose sum is equal to x
int count_1(Node* root1,Node* root2)
{
	if(root1==NULL||root2==NULL)return 0;
	
	stack <Node*> st1;
	stack <Node*> st2;
	
	Node* top1;
	Node* top2;
	
	int ct = 0;
	
	while(1)
	{
		while(root1!=NULL)
		{
			st1.push(root1);
			root1 = root1->left;
		}
		
		while(root2!=NULL)
		{
			st2.push(root2);
			root2 = root2->right;
		}
		
		if(st1.empty()||st2.empty())break;
		
		top1 = st1.top();
		top2 = st2.top();
		
		if(top1->data+top2->data==x)
		{
		    ct++;
		    
		    st1.pop();
		    st2.pop();
		    
		    root1 = top1->right;
		    root2 = top2->left;
		}
		else if(top1->data+top2->data<x)
		{
			st1.pop();
			root1 = top1->right;
		}
		else
		{
		    st2.pop();
			root2 = top2->left;	
		}
	}
	return ct;
}
int main()
{
	Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    
	inorder(root);
	cout<<endl;	
	insert(root,12);	
	inorder(root);
	Node* temp = search(root,3);
	if(temp)cout<<1<<endl;
	else cout<<0<<endl;
	Node* temp1 = deleteNode(root,3);
	inorder(temp1);
}
