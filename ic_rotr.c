#include "monty.h"
/**
  *rotr_ic - rotation time, rotates the stack to the bottom
  *@head: stack head that will be rotated
  *@counter: count the line_number
  *Return: return void
 */
void rotr_ic(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *duplicate;

	duplicate = *head;
	if ((*head)->next == NULL || *head == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *head;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*head)->prev = duplicate;
	(*head) = duplicate;
}
