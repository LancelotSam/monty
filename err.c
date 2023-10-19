#include "monty.h"
/**
 * err-this is the main function
 * It prints the appropiate error messages based on error codes
 * @error_code: error codes given by:
 * (1) => user does not provide a file or provides more than a single file
 * (2) => the file can't be read/opened
 * (3) => the file contains an invalid instruction
 * (4) => error allocatng memory
 * (5) => when push parameter is not an int
 * Return:void
 */
void err(int error_code, ...)
{
	va_list arg;
	char *op;
	int l_num;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n", va_arg(arg, char));
			break;
		case 3:
			1_num = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d unkown instruction %s\n", 1_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * err_2-this is the main function
 * it handles more cases for error codes
 * @error_code: the error codes for specific scenarios:
 * (6) => when the stack is empty for pint.
 * (7) => when the stack is empty for pop.
 * (8) => when stack is too short for operation
 * (9) => when dividing by zero
 * Return:void
 */
void err_2(int error_code, ...)
{
	va_list args;
	char *op;
	int l_num;

	va__start(args, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack is empty\n",
					va_arg(args, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop, stack is empty\n",
					va_arg(args, int));
			break;
		case 8:
			1_num = va_arg(args, unsigned int);
			op = va_arg(args, char *);
			fprintf(stderr, "L%d: cant %s, stack is too short\n", 1_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
					va_arg(args, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/**
 * err_3-this is the main function
 * it handles string errors
 * @error_code:the str associed error codes defined:
 * (10) => The No in a node is outside ASCII range
 * (11) => The stack is empty
 * Return:void.
 */
void err_3(int error_code, ...)
{
	va_list args;
	int l_num;

	va_start(args, error_code);
	l_num = va_arg(args, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't putchar, val is out of range", l_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't putchar, stack is empty\n", l_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
