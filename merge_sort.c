#include<stdio.h>
#include<stdlib.h>
  
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 

    struct node* Sorted(struct node* a,struct node* b){
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        struct node* result = NULL;
        if(a->data<=b->data){
            result =a;
            result->next = Sorted(a->next,b);
        }
        else{
            result = b;
            result->next = Sorted(a,b->next);
        }
        
        return result;
    }
 

    void Split(struct node* head,struct node** a,struct node** b){
        struct node* source=head;
        if(source == NULL || source->next == NULL){
            *a=source;
            *b=NULL;
	     return;
        }
        else{
            struct node *slow;
	    struct node* fast;
            slow = source;
            fast = source->next;
            while(fast!=NULL){
                fast=fast->next;
                if(fast!=NULL){
                    fast=fast->next;
                    slow=slow->next;
                }
            }
            
            *a=head;
            *b=slow->next;
            slow->next=NULL;
        }
    }

struct node* sortList(struct node* head){
        if(head==NULL || head->next==NULL)
            return head;
        struct node* a;
	struct node* b;
        Split(head,&a,&b);
        struct node* p;
	struct node* q;
        p = sortList(a);
	
        q = sortList(b);
        head = Sorted(a,b);
        
        return head;
    }
    
 

 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
  }
}
 
/* Function to insert a node at the beginging of the linked list */
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
  
/* Drier program to test above functions*/
int main()
{
  /* Start with the empty list */
  struct node* res = NULL;
  struct node* a = NULL;
  
  /* Let us create a unsorted linked lists to test the functions
   Created lists shall be a: 2->3->20->5->10->15 */
  push(&a, 3);
  push(&a, 2);
  push(&a, 4); 
  push(&a, 1); 
  push(&a, 8);  
  
  /* Sort the above created Linked List */
  res = sortList(a);
  
  printf("\n Sorted Linked List is: \n");
  printList(res);           
  
  getchar();
  return 0;
}
