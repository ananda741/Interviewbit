#include<iostream>
#include<limits.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

int minim = INT_MAX;

int Findmin(TreeNode *root){
	if(root == NULL) return 0;
	if(root->val < minim) minim = root->val;
	
	Findmin(root->left);
	Findmin(root->right);
	return minim;
}

TreeNode* Delete(TreeNode *root,int value){
	if(root == NULL)	
		return NULL;
	else if(root->val > value) 
		root->left = Delete(root->left,value);
	else if(root->val < value) 
		root->right = Delete(root->right,value);

	else{
		if(root->left == NULL && root->right == NULL){
			delete root;
			root = NULL;	
		}
		else if(root->left == NULL){
			TreeNode *temp = root;
			root = root->right;
			delete temp;
		}
		else if(root->right == NULL){
			TreeNode *temp = root;
			root = root->left;
			delete temp;
		}
		else{
			int minim = Findmin(root->right);
			root->val = minim;
			root->right = Delete(root->right,minim);
		}
	}
	return root; 
}

void inorder(TreeNode *root){
	if(root == NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

int main(){
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(2);
	root->right = new TreeNode(8);
	root->left->left = new TreeNode(1);	
	root->left->right = new TreeNode(4);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);
	root->left->right->left = new TreeNode(3);
	root->right->left->right = new TreeNode(7);
	root->right->right->right = new TreeNode(10);

	int value;
	cout<<"ELement : ";
	cin>>value;
	inorder(root);
	cout<<endl;
	Delete(root,value);
	inorder(root);
	cout<<endl;
}
