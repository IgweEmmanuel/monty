#include "monty.h"
/**
* free_stack_ic - frees a doubly linked list
* @head: head of the stack
*/
void free_stack_ic(stack_t *head)
{
	stack_t *sub;

	sub = head;
	while (head)
	{
		sub = head->next;
		free(head);
		head = sub;
	}
}
