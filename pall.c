#include "monty.h"

/**
 * pall - this prints all the stacks in the doubly linked list
 * @**stack: this is the stack
 * @line_num: this is the line number of the content in the file
 * @*value: this is the value of the content atoi to number
 *
 * Return: this returns void
 */

void pall(stack_t *stack, unsigned int line_num)
{
	(void)line_num;

	printf("The stacks are: ");
	while (stack != NULL)
	{
		printf("%d ", stack->n);
		stack = stack->next;
	}
	printf("\n");

}
