#include "monty.h"
/**
 * pall-this is the main function
 * it prints all the elements of a stack
 * @head:the head os the stack
 * Return:void
 */
void pall(const stack_t *head)
{
	if (head == NULL)
		exit(EXIT_FAILURE);

	while (head)
	{
		printf("%d\n", head->n);
		head = head->next;
	}
}

/**
 *nop-this is the main function
 * it does nothing
 * @head:head of the stack
 * @idx: the counter or current index
 * Return:void
 */
void nop(stack_t **head, unsigned int idx)
{
	(void) idx;
	(void) head;
}

/**
 * pop-this is the main function
 * It deletes the node at the top of the stack
 * @head: the pointer to the pointer of teh head of stack
 * @line_no: the line number in the opcode
 * Return:void
 */
void pop(stack_t **head, unsigned int line_no)
{
	stack_t *temp;

	if (*head == NULL || head == NULL)
		err_2(7, line_no);

	tmp = *head;
	*head = tmp->next;
	if (*head != NULL)
		(*head)->prev = NULL;
	free(tmp);
}

/**
 * pint-this is the main function
 * it prints the head node at the top of the list
 * @head:pointer to the pointer to the head of the list
 * @line_no: the line_no on opcode
 * Return:void
 */
void pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL || head == NULL)
		err_2(6, line_no);
	printf("%d\n", (*head)->n);
}

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
