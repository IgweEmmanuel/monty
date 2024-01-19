#include "monty.h"
/**
 * pstr_ic - this function will print string starting at the top of the stack
 * @head: head of stack, like the head you
 * @counter: counts line_number
 * Return: returns void
*/
void pstr_ic(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

/**This is the starting of this printing after counter is made unusable*/
	h = *head;
	while (h)
	{
		if (h->n <= 0 || h->n > 127)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
