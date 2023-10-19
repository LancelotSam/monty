#include "monty.h"
/**
 * open_file-this is the main function
 * It opens a provided file
 * @file_name:the name of the file
 * Return:void
 */
void open_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
		err(2, file_name);
	read_file(fd);
	fclose(fd);
}
/**
 * call_func-this is the main function
 * it calls the needed function
 * @func: a pointer to the function to be called
 * @op: he opcode in str format
 * @val: the numeric value
 * @ln: the line number containing the instruction
 * @format: specifiers, if 0 nodes will be added as a stack, if 1 as a queue
 * Return:void
 */
void call_func(op_func func, char *op, char *val, int ln, int format)
{
	stack_t *node;
	int flag, i;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			flag = -1;
		}
		if (val == NULL)
			err(5, ln);
		for (i = 0; val[i] != '\0'; i++)
		{
			if (isdigit(val[i]) == 0)
				err(5, ln);
		}
		node = create_node(atoi(val) * flag);
		if (format == 0)
			func(&node, ln);
		if (format == 1)
			add_to_queue(&node, ln);
	}
	else
		func(&head, ln);
}

/**
 * find_func-this is tthe main function
 * it finds the appropiate function
 * @opcode: opcode
 * @value:argument of opcode
 * @format: storage format-if 0 entered as stack
 * @ln: line number if 1 node is entered as a queue
 * Return:void
 */
void find_func(char *opcode, char *value, int ln, int format)
{
	int i;
	int flag;

	instruction_t funct_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_nodes},
		{"sub", sub_nodes},
		{"div", div_nodes},
		{"mul", mul_nodes},
		{"mod", mod_nodes},
		{"pchar", put_char},
		{"pstr", prnt_str},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;
	for (flag = 1, i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, func_list[i].opcode) == 0)
		{
			call_func(func_list[i].f, opcode, value, ln, format);
			flag = 0;
		}
	}
	if (flag == 1)
		err(3, ln, opcode);
}


/**
 * parse_line-this is the man function
 * It okenizees  the line to determine the function to call
 * @buffer: line from tthe file
 * @line_no: he line number
 * @format: storage format: if 0 or 1 nodes are enetered into the stack
 * Return: 0 if tthe opcode is stack, 1 if queue
 */
int parse_line(char *buffer, int line_no, int format)
{
	char *opcode, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
		err(4);
	opcode = strtok(buffer, delim);
	if (opcode == NULL)
		return (format);
	value = strtok(NULL, delim);
	if (strcmp(opcode, "stack") == 0)
		return (0);
	if (strcmp(opcode, "queue") == 0)
		return (1);
	find_func(opcode, value, line_numbr, format);
	return (format);
}

/**
 * read_file-this is the main function
 * it reads the provided file
 * @fd: pointer to file descriptor
 * Return:void
 */
void read_file(FILE *fd)
{
	int line_no, format = 0;
	char *buffer = NULL;
	size_t len = 0;

	for (line_no = 1; getline(&buffer, &len, fd) != -1; line_no++)
	{
		format = parse_line(buffer, linee_no, format);
	}
	free(buffer);
}
