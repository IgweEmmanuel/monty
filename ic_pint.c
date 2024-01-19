#include "monty.h"
/**
 * pint_ic - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pint_ic(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
