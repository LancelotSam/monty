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
