#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
 long long reverse(long num){
     long long s=0,rem;
     while(num){
         rem = num%10;
         num/=10;
         s = s*10 + rem;
     }
     return s;
 }
struct node* addTwoNumbers(struct node* l1, struct node* l2) {
    long long a=0,b=0,c,rem,flag =0 ;
    struct node* head1;
    struct node* head2;
    struct node* res=NULL;
    res = (struct node*)malloc(sizeof(struct node));
    head1 = l1;
    head2 = l2;
    while(head1!=NULL){
        a=a*10+(head1->data);
        head1=head1->next;
    }
    
    a = reverse(a);
    printf("a = %lld \n",a);
    while(head2!=NULL){
        b=b*10+(head2->data);
        head2=head2->next;
    }
    
    b = reverse(b);

    printf("b = %lld \n",b);
    
    c=a+b;
    
    printf("c = %lld \n",c);

    struct node* result= NULL;
    
    struct node* laser;
    struct node* maser;
    laser =(struct node*)malloc(sizeof(struct node));
    laser->data = c%10;
    c = c/10;
    laser->next = NULL;
    maser = laser;
    while(c){
	result = (struct node*)malloc(sizeof(struct node));
	rem = c%10;
	c = c/10;
	result->data = rem;
	result->next = NULL;
	maser->next = result;
	maser = maser->next;
    }
    return laser;
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginging of the linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
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
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    /* Start with the empty lists */
    struct node* a = NULL;
    struct node* b = NULL;
    struct node *intersect = NULL;
 
    /* Let us create the first sorted linked list to test the functions
     Created linked list will be 1->2->3->4->5->6 */
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 9);
    push(&a, 1);
 
    /* Let us create the second sorted linked list
     Created linked list will be 2->4->6->8 */
    //push(&b, 8);
    //push(&b, 3);
    //push(&b, 4);
    push(&b, 9);
 
    /* Find the intersection two linked lists */
    intersect = addTwoNumbers(a, b);
 
    printf("\n Linked list containing common items of a & b \n ");
    printList(intersect);
 
    return 0;
}
