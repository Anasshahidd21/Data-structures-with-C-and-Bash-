#include <stdio.h>
#include <stdlib.h>
int value=0;		//as a tester for Q6


typedef struct Node
{
	struct Node* prev;
	int data;
	struct Node* next;


}Node;

Node* create_dll_from_array(int arr[],int size){
	Node* head = NULL;
	Node* temp = NULL;
	Node* newNode = NULL;
	
	
	head = (Node*)malloc(sizeof(Node));		//created head-node
	head->prev=NULL;						//prev node null
	head->data = *(arr);					//inserted data for head
	head->next=NULL;						//next node null
	
	newNode=head;						

	value++;
	for (int i = 1; i < size; i++)
	{
		temp = (Node*)malloc(sizeof(Node));		//created new node
		temp->prev=NULL;
		temp->data=*(arr+i);					//i starts from 1 b/c 0th is already allocated to head
		temp->next=NULL;						
		
		
		
		newNode->next=temp;
		temp->prev=newNode;
		newNode=newNode->next;


		value++;
	}

	
return head;

	

}


void print_dll(Node * head){
	

while(head!=NULL){
	
	printf("%d\t", head->data);
	
	head= head->next;
}
printf("\n\n\t\t* * * * * *\n");
printf("\n");
}


void insert_after( Node* head, int valueToInsertAfter, int
valueToBeInserted){

 Node* traversal=head;

 Node* createNode;
 createNode = (Node*)malloc(sizeof(Node));
 createNode->next=NULL;
 createNode->prev=NULL;
 createNode->data=valueToBeInserted;

value++;

	while(traversal!=NULL)
	{
															

		if (traversal->data==valueToInsertAfter)
		{
			createNode->prev=traversal;
			createNode->next=traversal->next;
			traversal->next->prev=createNode;
			traversal->next=createNode;
			break;	
		}

		if(traversal->next==NULL){
			traversal->next=createNode;
			traversal->next->prev=traversal;
			traversal=traversal->next;
		}


		traversal=traversal->next;
	 
	}
	
}

void delete_element(Node* head, int valueToBeDeleted){

Node* traversal=head;
Node* temp=head;
Node* temp2=head;
//Node* try=head;
	
	while(traversal!=NULL)				//initailly used traversal								
	{

		if(head->next==NULL)
		{
			head=NULL;
		}

		if (traversal->next->next==NULL)				//For deleting last node
		{
			temp2=traversal->next;
			traversal->next->prev=NULL;
			traversal->next=NULL;
			free(temp2);
			temp2=NULL;
			value--;
			break;

		}


		if( traversal->next->data==valueToBeDeleted )		//for middle nodes
		{
			temp2=traversal->next;
			traversal->next=traversal->next->next;
			traversal->next->prev=traversal->next->prev->prev;
			free(temp2);
			temp2=NULL;
			value--;
			break;
		}

	
		if (temp->data==valueToBeDeleted)					//for head node
		{
			temp=temp->next;
			head->data=temp->data;
			head->prev=NULL;
			head->next=temp->next;
			free(temp);
			value--;
			break;
		}
		 
		traversal=traversal->next;
	}
	
	if (traversal->data!=valueToBeDeleted)
	{
		return;
	}
}


void sort_dll(Node* head){
Node* j = head;
Node* i = head;
int temp = 0;

for (i=head; i!=NULL; i=i->next)
{
	for (j = i->next ; j!=NULL ; j=j->next)
	{
		if (i->data > j->data)
		{
			temp = i->data;
			i->data = j->data;
			j->data = temp;
			break;
		}
	}
}

}


void free_me(Node* head){
	Node *p; 
	Node *new=NULL;
	p=head;
	    
    while(p!=NULL){
    	new=p->next;
    	free(p);
    	p=new;
    	value--;
    	
    }
     //printf("%d\n",value );		//You can uncomment this print, it will give you a value of zero after all the incremention(when a new malloc is done) and decremention(once it is freed). 

}




int main ()
{
int array [ 5 ] = { 11 , 2 , 7 , 22 , 4 };
Node* head;



/* Question 1 */
head = create_dll_from_array( array , 5 ); //size of array is 5
/* Question 2 */
print_dll(head);



// /* Question 3 */
// // To insert 13 after the first occurence of 7
insert_after(head, 7 , 13 );

// // To insert 29 after the first occurence of 21
 insert_after(head, 21 , 29 );
 print_dll(head);


//  Question 4 
 delete_element(head, 22 );
 print_dll(head);
 delete_element(head, 11 );	
 print_dll(head);



// /* Question 5 */
 sort_dll(head);
 print_dll(head);


// /* Question 6 */
 free_me(head);





return 0 ;



}
