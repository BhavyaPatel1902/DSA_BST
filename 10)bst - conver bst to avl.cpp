#include<bits/stdc++.h>
using namespace std;
struct Node 
{ 
    int data; 
    Node* left,  *right; 
}; 
Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return (node); 
} 
void storeBSTNodes(Node* root, vector<Node*> &nodes) 
{ 
    // Base case 
    if (root==NULL) 
        return; 
  
    // Store nodes in Inorder (which is sorted 
    // order for BST) 
    storeBSTNodes(root->left, nodes); 
    nodes.push_back(root); 
    storeBSTNodes(root->right, nodes); 
} 
Node* buildTreeUtil(vector<Node*> &nodes, int start, 
                   int end) 
{ 
    // base case 
    if (start > end) 
        return NULL; 
  
    /* Get the middle element and make it root */
    int mid = (start + end)/2; 
    Node *root = nodes[mid]; 
  
    /* Using index in Inorder traversal, construct 
       left and right subtress */
    root->left  = buildTreeUtil(nodes, start, mid-1); 
    root->right = buildTreeUtil(nodes, mid+1, end); 
  
    return root; 
} 
Node* buildTree(Node* root) 
{ 
    // Store nodes of given BST in sorted order 
    vector<Node *> nodes; 
    storeBSTNodes(root, nodes); 
  
    // Constucts BST from nodes[] 
    int n = nodes.size(); 
    return buildTreeUtil(nodes, 0, n-1); 
} 
/* Function to do preorder traversal of tree */
void preOrder(Node* node) 
{ 
    if (node == NULL) 
        return; 
    printf("%d ", node->data); 
    preOrder(node->left); 
    preOrder(node->right); 
}
int main()
{
	Node* root = newNode(10); 
    root->left = newNode(8); 
    root->left->left = newNode(7); 
    root->left->left->left = newNode(6); 
    root->left->left->left->left = newNode(5); 
  
    root = buildTree(root); 
  
    printf("Preorder traversal of balanced "
            "BST is : \n"); 
    preOrder(root); 
  
    return 0; 
}
