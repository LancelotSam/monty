#include "monty.h"
/**
 * f_pall-this is the main function
 * it prints all the elements of a stack
 * @head:the head os the stack
 * @line_no: unused
 * Return:void
 */
void f_pall(stack_t **head, unsigned int line_no)
{
        stack_t *h;
        (void) line_no;

        h = *head;
        if (h == NULL)
                return;
        while (h)
        {
                printf("%d\n", h->n);
                h = h->next;
        }
}

/**
 * f_nop-this is the main function
 * it does nothing
 * @head:head of the stack
 * @line_no: the counter or current index
 * Return:void
 */
void f_nop(stack_t **head, unsigned int line_no)
{
        (void) line_no;
        (void) head;
}

/**
 * f_pop-this is the main function
 * It deletes the node at the top of the stack
 * @head: the pointer to the pointer of teh head of stack
 * @line_no: the line number in the opcode
 * Return:void
 */
void f_pop(stack_t **head, unsigned int line_no)
{
        stack_t *h;

        if (*head == NULL)
        {
                fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        *head = h->next;
        free(h);
}
/**
 * f_top-this is the main function
 * it prints the head node at the top of the list
 * @head:pointer to the pointer to the head of the list
 * @line_no: the line_no on opcode
 * Return:void
 */
void f_top(stack_t **head, unsigned int line_no)
{
        (void)head;
        (void)line_no;
        bus.lifi = 0;
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
