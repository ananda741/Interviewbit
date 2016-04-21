#include<stdio.h>
#include<stdlib.h>
  

struct node
{
   int data;
   struct node* left;
   struct node* right;
};
 

void printPaths(struct node* node) 
{
  int path[1000];
  printf("%d ",printPathsRecur(node, path, 0));
}
 
int p,q,i,sum = 0;
int printPathsRecur(struct node* node, int path[], int pathLen) 
{
  if (node==NULL) 
    return 0;
 
  path[pathLen] = node->data;
  pathLen++;
 
  int laser = 0;  

  if (node->left==NULL && node->right==NULL) 
  {
    for(i=0;i<pathLen;i++)
        laser=laser*10 + path[i];
    sum+=laser;
  }
  else
  {
   
    p = printPathsRecur(node->left, path, pathLen);
    q = printPathsRecur(node->right, path, pathLen);
  }
  
  return sum;
}
    
 
 
struct node* newnode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  
  return(node);
}
  

int main()
{ 
  
  /* Constructed binary tree is
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  struct node *root = newnode(0);
  root->left        = newnode(1);
  //root->right       = newnode(2);
  //root->left->left  = newnode(3);
  //root->left->right = newnode(5);
  //root->right->left = newnode(2);
  
  printPaths(root);
  
  getchar();
  return 0;
}
