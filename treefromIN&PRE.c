#include<stdio.h>
#include<stdlib.h>
 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct node
{
  int data;
  struct node* left;
  struct node* right;
};


int search(int arr[],int start,int end,int val){
	int i;
	for(i=start;i<=end;i++){
		if(arr[i] == val)
			break;
	}
	return i;
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

struct node* buildTre(int in[],int *pre,int start,int end){
	static preindex = 0;	
	if(start > end)
		return NULL;
	
	struct node* vivek;
	vivek = newNode(pre[preindex++]);

	if(start == end)
		return vivek;

	int index;
	index = search(in,start,end,vivek->data);
	
	vivek->left = buildTre(in,pre,start,index-1);
	vivek->right = buildTre(in,pre,index+1,end);

	return vivek;
}


struct node* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    struct node* maser;
    maser = buildTre(inorder,preorder,0,inorderSize-1);
    return maser;
}

 
/* This funtcion is here just to test buildTree() */
void printInorder(struct node* node)
{
  if (node == NULL)
     return;
 
  /* first recur on left child */
  printInorder(node->left);
 
  /* then print the data of node */
  printf("%c ", node->data);
 
  /* now recur on right child */
  printInorder(node->right);
}
 
/* Driver program to test above functions */
int main()
{
  int in[] = {1,2};
  int pre[] = {1,2};
  int len = sizeof(in)/sizeof(in[0]);
  struct node *root = buildTree(in, len, pre, len);
 
  /* Let us test the built tree by printing Insorder traversal */
  printf("\n Inorder traversal of the constructed tree is \n");
  printInorder(root);
  getchar();
}
