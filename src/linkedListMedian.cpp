/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

int findLength(struct node *);

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	int m;

	if (head==NULL)
	return -1;

	int len = findLength(head); //Find the length of linked list
	struct node *temp = head;

	if (len % 2 == 0)    //Return the average of middle two nodes if length is even
	{	
		for (int i = 1; i <len / 2; i++)
			temp = temp->next;
		m = (temp->num + temp->next->num) / 2;
	}
	else
	{
		for (int i = 0; i <len / 2; i++) //Return the middle node if length is odd
			temp = temp->next;
		m = temp->num;
	}
	return m;
}

int findLength(struct node *head)
{
	int count = 0;
	struct node *temp = head;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}