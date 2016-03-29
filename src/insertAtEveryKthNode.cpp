/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

int findListLen(struct node *);
struct node* insertAtPos(struct node *, int, int);

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	if (head == NULL) return NULL; //Check for null cases
	if (K <= 0) return NULL;
	int p = K+1;
	int n = K;
	
	while (1)
	{
		int len = findListLen(head); //Find the length of the list  
		if (K > len) return head; //If K is greater than len then return the list
        insertAtPos(head, n, K); //Insert new node at every Kth node 
		K = K + p; //Find the next Kth position
	}
}

//Function to find the length of list
int findListLen(struct node *head)
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

//Function to insert new node at every Kth node
struct node* insertAtPos(struct node *head, int n, int pos)
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	node->num = n;  //Create a new node
	node->next = NULL;

	struct node *prev = NULL;
	struct node *current = head;
	int i;

	for (i = 0; i <pos;i++) {
		prev = current;        //Traverse until one position before the position required
		current = current->next;
	}
	node->next = prev->next; //Place the next node of prev to the next new node
	prev->next = node; //Make the new node as the next node of prev
	
	return head;
}