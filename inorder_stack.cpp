#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

struct tNode{
	int data;
	struct tNode *left,*right;
};

void leftmost(tNode* current,stack<tNode*> &laser){
	if(current == NULL)
		return;
	while(current!=NULL){
		laser.push(current);
		current = current->left;
	}
}

void Inorder(tNode* root){
	if(root == NULL)
		return;
	stack<tNode*> laser;
	leftmost(root,laser);
	while(!laser.empty()){
		cout<<laser.top()->data<<" ";
		root = laser.top()->right;
		laser.pop();
		leftmost(root,laser);		
	}
}


struct tNode* newtNode(int data)
{
  struct tNode* node = new tNode;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 
/* Driver program to test above functions*/
int main()
{
 
  /* Constructed binary tree is
            1
          /   \
        2      3
      /  \
    4     5
  */
  struct tNode *root = newtNode(1);
  root->left        = newtNode(2);
  root->right       = newtNode(3);
  root->left->left  = newtNode(4);
  root->left->right = newtNode(5); 
 
  Inorder(root);
 
  getchar();
  return 0;
}
