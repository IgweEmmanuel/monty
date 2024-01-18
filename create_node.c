#include "monty.h"

/**
 * *create_node - this is a pointer function to create new nodes
 * @value: this is the value of the stack
 *
 * Return: this returns new_node
 */ 
stack_t *create_node(int value)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		perror("Error: Could not allocate memory");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	return new_node;
}
