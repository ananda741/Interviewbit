#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};
 
/* Function to pairwise swap elements of a linked list */

struct node* Kswap(struct node* head, int pos)
{
	int len=0,k=1,p=1;
	struct node* temp,*maser,*laser;
	temp = head;
	while(temp!=NULL){
		temp = temp->next;
		len++;
	}
	if(pos == 0)
		return head;
	if(pos == 1){
		if(len == 2){
			temp = head->next;
			temp->next = head;
			head->next = NULL;
			head = temp;
		}
		else{
			temp = head;
			while(temp->next->next!=NULL)
				temp=temp->next;
			maser = temp->next;
			laser = head->next;	
			temp->next = head;
			head->next = NULL;
			maser->next = laser;
			head = maser;
		}
	}
	else{
		laser = head;
		while(k!=pos-1 && laser->next!=NULL){
			laser = laser->next;
			k++;
		}
		maser = head;
		while(p!=len-pos && maser->next!=NULL){
			maser = maser->next;
			p++;
		}

		if(laser == maser)
			return head;

		else{
			struct node* a,*b,*x;
			a = laser->next;
			b = maser->next;
			laser->next = b;
			maser->next = a;
			x = a->next;
			a->next = b->next;
			b->next = x;
		}
	}
	return head;
}
 
/* Function to add a node at the begining of Linked List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7*/
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3); 
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling  pairWiseSwap() ");
    printList(start);
 
    start = Kswap(start,3);
 
    printf("\n Linked list after calling  pairWiseSwap() ");
    printList(start);
 
    getchar();
    return 0;
}
