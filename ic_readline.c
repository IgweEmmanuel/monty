#include "monty.h"

/**
 * *readline - this reads line using malloc to assign size
 * @file: this is the file as parameter
 *
 * Returns: it returns character
 */
char *read_line(FILE *file)
{
	char buffer[MAX_LINE_LENGTH];
	char *line = malloc(strlen(buffer) + 1);
	size_t len = strlen(line);
	size_t i;

	if (fgets(buffer, sizeof(buffer), file) == NULL)
	{
        /* Return NULL if no more lines to read or an error occurred */
		return NULL;
	}

    /* Allocate memory for the line and copy the content */
    
	if (line == NULL)
	{
		perror("Error allocating memory for line");
		exit(EXIT_FAILURE);
	}
	strcpy(line, buffer);

    /* Remove newline character at the end of the line */

	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';

    /* Replace '$' with a space */
	for (i = 0; i < len; i++)
	{
		if (line[i] == '$')
			line[i] = ' ';
	}

	return line;
}
