#include "monty.h"
/**
 * main-the eentry point of the program
 * @argc: the numbeer of arguments
 * @argv: an aray of arguments
 * Return: 0
 */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file \n");
		exit(EXIT_FAILURE);
	}
	open_file(argv[1]);
	free_stack();
	return (0);
}
/**
 * queue-this is the main function
 * it adds a ode to the queue
 * @new_node: a pointer tto the newly added node
 * Return: void
 */
void queue(stack_t **new_node)
{
	stack_t *temp;

	if (*new_node == NULL || new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *new_nodee;
	(*new_node)->prev = temp;
}
