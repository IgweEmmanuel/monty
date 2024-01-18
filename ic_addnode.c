#include "monty.h"
/**
 * addnode_ic - add node to the head stack
 * @head: head of the stack
 * @n: new_value
 * Return: no return
*/
void addnode_ic(stack_t **head, int n)
{

	stack_t *new_node, *sub;

	sub = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (sub)
		sub->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
