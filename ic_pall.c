#include "monty.h"

/**
 * pall_ic - prints the stack nodes
 * @head: the head of the stack
 * @counter: the counter
 *
 * Return: return void
 */
void pall_ic(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
