#include "monty.h"
/**
 * pop_ic - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pop_ic(stack_t **head, unsigned int counter)
{
	stack_t *sub;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	sub = *head;
	*head = sub->next;
	free(sub);
}
