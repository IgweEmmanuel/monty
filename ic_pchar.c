#include "monty.h"
/**
 * pchar_ic - the function will print character at the top of the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void pchar_ic(stack_t **head, unsigned int counter)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: Oh no, can't pchar, stack empty\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n < 0 || h->n > 127)
	{
		fprintf(stderr, "L%d: heya can't pchar, value out of range\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
