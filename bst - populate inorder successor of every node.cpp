#include<bits/stdc++.h>
using namespace std;
class node 
{ 
    public:
    int data; 
    node *left; 
    node *right; 
    node *next; 
};
node* newnode(int data) 
{ 
    node* Node = new node();
    Node->data = data; 
    Node->left = NULL; 
    Node->right = NULL; 
    Node->next = NULL; 
 
    return(Node); 
}

void populateNext(node* root)
{
	static node* next = NULL;
	
	if(root)
	{
		populateNext(root->right);
		
		root->next = next;
		
		next = root;
		
		populateNext(root->left);
	}
}
int main()
{
	node *root = newnode(10); 
    root->left = newnode(8); 
    root->right = newnode(12); 
    root->left->left = newnode(3); 
 
    // Populates nextRight pointer in all nodes 
    populateNext(root); 
 
    // Let us see the populated values 
    node *ptr = root->left->left; 
    while(ptr) 
    { 
        // -1 is printed if there is no successor 
        cout << "Next of " << ptr->data << " is "
             << (ptr->next? ptr->next->data: -1) 
             << endl; 
        ptr = ptr->next; 
    } 
 
    return 0; 
}
