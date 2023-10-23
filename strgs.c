#include "monty.h"
/**
 * print_char-this is the main function
 * it prints the char at the top of stack
 * @head: the p to the p of the head of stack
 * @line_no: line number in opcode
 * Return:void
 */
void print_char(stack_t **head, unsigned int line_no)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}

/**
 * print_str-this is the main function
 * It prints a string starting from top of the stack
 * @head:head of stack
 * @line_no: line number
 * Return: void
 */
void print_str(stack_t **head, unsigned int line_no)
{
	stack_t *h;
	(void)line_no;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
