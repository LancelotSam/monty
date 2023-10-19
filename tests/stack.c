#include "monty.h"
/**
 * push-this is the main function
 * it pushes elements to the top of the stack
 * @head:the head of the sttack
 * @idx:the counter
 * Return:void
 */
void push(stack_t **head, unsigned int idx)
{
	if (*head == NULL)
	{
		printf("Stack underflow\n");
	}


