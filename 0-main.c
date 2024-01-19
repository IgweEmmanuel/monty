#include "monty.h"
channel_t channel = {NULL, NULL, NULL, 0};

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/

int main(int argc, char *argv[])
{
	char buffer[BUFFER_SIZE];
	FILE *file;

	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	channel.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(buffer, sizeof(buffer), file) != NULL)
	{
		size_t read_line = strlen(buffer);
		char *content = malloc(read_line + 1);

		if (content == NULL)
		{
			perror("Error allocating memory for line");
			exit(EXIT_FAILURE);
		}

		strcpy(content, buffer);
		channel.content = content;
		counter++;

		if (read_line > 0)
		{
			execute_ic(content, &stack, counter, file);
		}

		free(content);
	}

	free_stack_ic(stack);
	fclose(file);

	return 0;
}

