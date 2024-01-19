#include "monty.h"
/**
 * mod_ic - the function finds the modal of the top two stacks
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void mod_ic(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, sub;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	sub = h->next->n % h->n;
	h->next->n = sub;
	*head = h->next;
	free(h);
}
