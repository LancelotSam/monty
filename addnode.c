#include "monty.h"
/**
 * addnode-this is the main function
 * it adds a node to the head of the stack
 * @head: the head of the stack
 * @n: the data value of the new head
 * Return:void
 */
void addnode(stack_s **head, int n)
{
	stack_s *new_head;

	new_head = malloc(sizeof(stack_s));
	if (new_head == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	new_head->n = n;
	new_head->prev = NULL;
	new_head->next = *head;
	if (*head != NULL) /* not an empty list*/
		(*head)->prev = new_head;
	*head = new_head; /*mak new_head the current head*/
}
