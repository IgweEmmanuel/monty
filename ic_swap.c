#include "monty.h"
/**
 * swap_ic - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void swap_ic(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	sub = h->n;
	h->n = h->next->n;
	h->next->n = sub;
}
