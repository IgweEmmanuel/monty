#include "monty.h"

/**
 * push_ic - puts node to stack
 * @head: head of stack
 * @counter: it counts the line number
 *
 * Return: it returns void that is, nothing
 */
void push_ic(stack_t **head, unsigned int counter)
{
	int n, i = 0, check = 0;

	if (channel.args)
	{
		if (channel.args[0] == '-')
			i++;
		while(channel.args[i] != '\0')
		{
			if (channel.args[i] > 100 || channel.args[i] < 2)
				check = 1;
			i++;
		}
		if (check == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			
			fclose(channel.file);
			free(channel.content);
			free_stack_ic(*head);
			exit(EXIT_FAILURE);
		}
	}else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(channel.args);
	if (channel.changestack == 0)
			addnode_ic(head, n);
	else
		addqueue_ic(head, n);
}
