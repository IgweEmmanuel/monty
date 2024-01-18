#include "monty.h"
/**
 * read_line - this reads the lines in the file
 * @file: this is the file
 *
 * Return: this returns character
 */
char *read_line(FILE *file)
{
	char buffer[MAX_LINE_LENGTH];
	char *line = malloc(strlen(buffer + 1));
	size_t len = strlen(line);

	if (fgets(buffer, sizeof(buffer), file) == NULL)
	{
		return NULL;
	}

	if (line == NULL)
	{
		perror("Error allocating memory for line");
		exit(EXIT_FAILURE);
	}
	strcpy(line, buffer);

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	
	return line;
}
