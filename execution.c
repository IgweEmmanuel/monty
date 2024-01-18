#include "monty.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
/**
 * execute - this is the function that executes the files
 * @*filename: this is the file to use
 * @**stac: this is the stack
 *
 * Return: this returns void
 */
void execution(const char *filename, stack_t **stack, instruction_t *instructions, size_t num_instructions)
{
	
	char *file_line;
	unsigned int line_num = 0;
	char opcode[12];
	char value[32];
	size_t i;
	
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		perror("Error: cant open the file");
		exit(EXIT_FAILURE);
	}

	while ((file_line = read_line(file)) != NULL)
	{
		line_num++;
		
		if (sscanf(file_line, "%9s %19s", opcode, value) >= 1)
		{
			for (i = 0; i < num_instructions; i++)
			{
				if (strcmp(opcode, instructions[i].opcode) == 0)
				{
					instructions[i].f(stack, line_num, value);
					break;
				}
			}
		}
		free(file_line);
	}
	fclose(file);

}
