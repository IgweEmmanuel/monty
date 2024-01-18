#include "monty.h"

/**
 * push - this is the function that puts values into a linked list stack
 * @**stack: this is the stack to be pushed into the linked list
 * @line_num: this is the line number of the content of the file to be read from
 * @*value: this is the value of the created stack to be added to the linked list.
 *
 * Return: this returns void
 */ 
void push(stack_t **stack, unsigned int line_num, const char *value)
{
	int stack_value = atoi(value);
	stack_t *new_node = create_node(stack_value);

	if (value == NULL || value[0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);	
	}
	
	if (stack_value == 0 && value[0] != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	
	if (*stack != NULL)
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}

	*stack = new_node;

}
