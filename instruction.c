#include "monty.h"
/**
 * exec_func - executes the opcode
 * @stack: head pf list
 * @line_no: line_counter
 * @file: poiner to monty file
 * @content: line content
 * Return: void
 */
int exec_func(char *content, stack_t **stack, unsigned int line_no, FILE *file)
{
        instruction_t opst[] = {
                {"push", f_push}, {"pall", f_pall}, {"pint", f_top},
                {"pop", f_pop},
                {"swap", swap_nodes},
                {"add", add_nodes},
                {"nop", f_nop},
                {"sub", sub_nodes},
                {"div", div_nodes},
                {"mul", mul_nodes},
                {"mod", mod_nodes},
                {"pchar", print_char},
                {"pstr", print_str},
                {"queue", f_queue},
                {"stack", f_top},
                {NULL, NULL}
        };
        unsigned int i = 0;
        char *op;

        op = strtok(content, " \n\t");
        if (op && op[0] == '#')
                return (0);
        bus.arg = strtok(NULL, " \n\t");
        while (opst[i].opcode && op)
        {
                if (strcmp(op, opst[i].opcode) == 0)
                {       opst[i].f(stack, line_no);
                        return (0);
                }
                i++;
        }
        if (op && opst[i].opcode == NULL)
        { fprintf(stderr, "L%d: unknown instruction %s\n", line_no, op);
                fclose(file);
                free(content);
                free_stack(*stack);
                exit(EXIT_FAILURE); }
        return (1);
}
