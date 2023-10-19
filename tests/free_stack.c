#include "monty.h"
/**
 * free_stack-this is the main function
 * it frees the stack
 * @head: this is the head of the stack
 * Return:void
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
