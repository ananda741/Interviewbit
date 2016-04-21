#include <stdio.h>
#include <stdlib.h>
 
// A linked list node
struct node
{
    int data;
    struct node *next;
};
 
/* Function to insert a node at the beginning */
void push(struct node ** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)  = new_node;
}
 
/* Function to print linked list */
void printList(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
 
struct node* reverseBetween(struct node* head, int m, int n) {
    long long len=0,count =1;
    if(head==NULL||head->next==NULL||m==n)
        return head;
    struct node* temp;
    temp = head;
    while(temp!=NULL){
        temp = temp->next;
        len++;
    }
    
    //printf("len-- %lld",len);
    struct node* current=NULL;
    struct node* tail=NULL;
    struct node* second=NULL;
    
    if(m==1){
        current = head;
    }
    else{
        temp = head;
        while(count!=m-1 && temp->next!=NULL){
            temp = temp->next;
            count++;
        }
        current = temp->next;
        temp->next = NULL;
    }
    if(n==len){
        temp = head;
        while(temp->next!=NULL)
            temp= temp->next;
        tail = temp;
    }
    else{
        temp = current;
        count = 1;
        while(count!=n-m+1 && temp->next!=NULL){
	    printf("laser\n");
            temp = temp->next;
            count++;
        }
	printf("temp->data = %d  n= %d  count = %lld \n",temp->data,n,count);
        tail = temp;
        second = temp->next;
        tail->next = NULL;
    }
    
    struct node* wemp = NULL;
    struct node* node;

    //printf("current->data::%d\n",current->data);
    //printf("tail->data::%d\n",tail->data);    
    while(current!=NULL){
        node = current->next;
        current->next = wemp;
        wemp = current;
        current = node;
    }
    
    //printf("wemp->data  %d",wemp->data);
  
    if(m==1)
        head = wemp;
    
    temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    if(m!=1)    
    	temp->next = wemp;
    
    while(temp->next!=NULL)
        temp = temp->next;
        
    temp->next = second;
    
    return head;
}
 
// Driver program to test above functions
int main()
{
    /* Create following linked list
      1->2->3->4->5->6->7->8->9->10 */
    struct node* head = NULL;
    int M=2, N=4;
    //push(&head, 10);
    //push(&head, 9);
    //push(&head, 8);
    //push(&head, 7);
    //push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
 
    printf("M = %d, N = %d \nGiven Linked list is :\n", M, N);
    printList(head);
 
    head = reverseBetween(head, M, N);
 
    printf("\nLinked list after deletion is :\n");
    printList(head);
 
    return 0;
}
