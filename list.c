#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);
	int found=0;
	int found2=0;
	list_t *temp=head;

    while(!found)
    {


		if((temp->index)>=(new_element->index)){if(temp==head){new_element->next=head; head=new_element;}
												found=1;new_element->next=temp;}
		else{if(temp->next==NULL){temp->next=new_element;new_element->next=NULL;found=1;}else{temp=temp->next;}}
	}	
	
	list_t *temp2=head;

	if(new_element!=head )
{
    while(!found2)
	{

		if(temp2->next==new_element->next){found2=1;temp2->next=new_element;}
		else{if((temp2->next)->next==NULL){found2=1;}else{temp2=temp2->next;}}
	}
}
	assert(head->next!=head);

	return head;
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);
	
if(head->next!=NULL)
{	
	list_t *temp=head->next;
	head->next=NULL;
	list_t *temp2=temp->next;
	temp->next=head;

	list_t *temp3=temp2->next;
	temp2->next=temp;

	if(temp2!=NULL)
	{
	int done=0;


		while(!done)
		{	

		if(temp3->next==NULL){done=1;temp3->next=temp2;}
		else{temp=temp3->next;temp3->next=temp2;temp2=temp3;temp3=temp;}
		}
	}
	head=temp3;
}

	return head;
}
