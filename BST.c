#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int data;
	struct Node*right;
	struct Node*left;
}Node;
Node*root=NULL;
Node* createNode(int value){
	Node* newNode=(Node*)malloc(sizeof(Node));
	newNode->data=value;
	newNode->left=NULL;
	newNode->right=NULL;
	return newNode;
}
Node* InsertL(Node* root,int val){
	root->left = createNode(val);
	return root -> left;
}
Node* InsertR(Node* root,int val){
	root->right = createNode(val);
	return root -> right;
}
Node* inorder(Node* root){
	if(root!=NULL){
	 inorder(root->left);
	 printf("%d->",root->data);
	 inorder(root->right);
	 }
}
Node* InsertNode(Node* node,int val){
	if(node==NULL)
		return createNode(val);
	else{
		if(val>node->data)
		node->right=InsertNode(node->right,val);
		else
		node->left=InsertNode(node->left,val);
	}
	return node;
}
int main(){
	root=InsertNode(root,30);
	root=InsertNode(root,20);
	root=InsertNode(root,25);
	root=InsertNode(root,15);
	root=InsertNode(root,4);
	root=InsertNode(root,3);
	
	inorder(root);
		}
	
	
	
	
	
	
	
	
	
	
	
	
	
