#include "monty.h"
/**
 * _pall-this is the main function
 * it prints all the elements of a stack
 * @head:the head os the stack
 * Return:void
 */
void _pall(const stack_s *head)
{
	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}
