#include "monty.h"
/**
 * queue_ic - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void queue_ic(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	channel.changestack = 1;
}

/**
 * addqueue_ic - add node to the tail stack
 * @n: new_value
 * @head: head of the stack
 * Return: no return
*/
void addqueue_ic(stack_t **head, int n)
{
	stack_t *new_node, *sub;

	sub = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (sub)
	{
		while (sub->next)
			sub = sub->next;
	}
	if (!sub)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		sub->next = new_node;
		new_node->prev = sub;
	}
}
