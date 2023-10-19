#include "monty.h"
/**
 * push-this is the main function
 * it pushes elements to the top of the stack
 * @new_node: pointer to the po of a newly created node
 * Return:void
 */
void push(stack_t **new_node)
{
	stack_t *temp;

	if (*new_node == NULL || new_node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL) /* if list is empty*/
	{
		head = *new_node;
		return;
	}
	temp = head;
	head = *new_node;
	head->next = temp;
	temp->prev = head;
}
/**
 * newhead-this is the main function
 * it adds a node to the head of the stack
 * @head: the head of the stack
 * @n: the data value of the new head
 * Return:void
 */
void newhead(stack_t **head, int n)
{
	stack_t *new_head;

	new_head = malloc(sizeof(stack_t));
	if (new_head == NULL)
	{
		frintf(stderr, "Error\n");
		exit(0);
	}
	new_head->n = n;
	new_head->prev = NULL;
	new_head->next = *head;
	if (*head != NULL) /* not an empty list*/
		(*head)->prev = new_head;
	*head = new_head; /*mak new_head the current head*/
}
/**
 * create_node-this is the main function
 * it creates a new node
 * @n: the data to be contained in the new node
 * Return:pointer to the node, or NULL
 */
stack_t *create_node(int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		err(4);
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->n = n;
	return (new_node);
}

/**
 * mod_nodes-this is the main function
 * It finds the modular of nodes
 * @head: the p to he p of the head
 * @line_no:the line number of the func on opcode
 * Return:void
 */
void mod_nodes(stack_t **head, unsigned int line_no)
{
	int mod;

	if (*head == NULL || (*head)->next == NULL || head == NULL)
		err_2(8, line_no, "mod");
	if ((*head)->n == 0)
		err_2(, line_no);
	(head) = (*head)->next;
	mod = (*head)->n % (*head)->prev->n;
	(*head)->n = mod;
	free((*head)->prev);
	(*head)->prev = NULL;
}
