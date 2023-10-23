/**
 * f_push-this is the main function
 * it pushes elements to the top of the stack
 * @head: stack head
 * @line_no: the line number
 * Return:void
 */
void f_push(stack_t **head, unsigned int line_no)
{
        int n, j = 0, flag = 0;

        if (bus.arg)
        {
                if (bus.arg[0] == '-')
                        j++;
                for (; bus.arg[j] != '\0'; j++)
                {
                        if (bus.arg[j] > 57 || bus.arg[j] < 48)
                                flag = 1; }
                if (flag == 1)
                { fprintf(stderr, "L%d: usage: push integer\n", line_no);
                        fclose(bus.file);
                        free(bus.content);
                        free_stack(*head);
                        exit(EXIT_FAILURE); }}
        else
        { fprintf(stderr, "L%d: usage: push integer\n", line_no);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE); }
        n = atoi(bus.arg);
        if (bus.lifi == 0)
                newhead(head, n);
        else
                addqueue(head, n);
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
                fprintf(stderr, "Error\n");
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
 * mod_nodes-this is the main function
 * It finds the modular of nodes
 * @head: the p to he p of the head
 * @line_no:the line number of the func on opcode
 * Return:void
 */
void mod_nodes(stack_t **head, unsigned int line_no)
{
        stack_t *h;
        int len = 0, aux;

        h = *head;
        while (h)
        {
                h = h->next;
                len++;
        }
        if (len < 2)
        {
                fprintf(stderr, "L%d: can't mod, stack too short\n", line_no);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        h = *head;
        if (h->n == 0)
        {
                fprintf(stderr, "L%d: division by zero\n", line_no);
                fclose(bus.file);
                free(bus.content);
                free_stack(*head);
                exit(EXIT_FAILURE);
        }
        aux = h->next->n % h->n;
        h->next->n = aux;
        *head = h->next;
        free(h);
}
