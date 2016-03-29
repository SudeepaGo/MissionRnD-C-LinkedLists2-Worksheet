/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

void insertNode(struct node **,struct node **);

struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL && head2 == NULL)
		return NULL;
	struct node *result = NULL;
	struct node **head = &result;
	
	while (1)
	{
		if (head1 == NULL)  //If all the nodes of head1 are traversed then merge head2
		{
			*head = head2;
			break;
		}
		else if (head2 == NULL)  //If all the nodes of head2 are traversed then merge head1
		{
			*head = head1;
			break;
		}
		if (head1->num <= head2->num) //If the node of head1 is of lesser value,then insert it first in new list
		{
			insertNode(head, &head1);

		}
		else
		{
			insertNode(head, &head2); //If the node of head2 is of lesser value,then insert it first in new list
		}
		head = &((*head)->next); //Advance the new list
	}
	return result;
}
 
//Function toplace the source node from head1 or head2 into new list head 
void insertNode(struct node **destNode, struct node **srcNode)
{
	struct node *temp = *srcNode;
	*srcNode = temp->next;
	*destNode = temp;
}