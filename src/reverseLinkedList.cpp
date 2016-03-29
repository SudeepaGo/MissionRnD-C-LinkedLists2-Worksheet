/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head==NULL)          //Check for null cases
	return NULL;

	struct node *current = head;    //Assign head to a node called current
	struct node *previous = NULL;
	struct node *temp;

	while (current != NULL)         //Continue while the linked list exists
	{
		temp = current->next;      //First store the next value of current node in a temp node
		current->next = previous;  //Assign the previous node to the next of current node
		previous = current;        //Now the current node comes to the opposite end
		current = temp;            //Traversal continues with the next value of earlier current node
	}
	head = previous;               //At last make the previous node as head
	return head;
}
