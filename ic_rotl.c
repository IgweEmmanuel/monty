#include "monty.h"
/**
  *rotl_ic- rotates the stack to the top
  *@head: stack head
  *@counter: counts the line_number
  *Return: return void
 */
void rotl_ic(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *tmp = *head, *sub;

	if ((*head)->next == NULL || *head == NULL)
	{
		return;
	}
	sub = (*head)->next;
	sub->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = sub;
}
