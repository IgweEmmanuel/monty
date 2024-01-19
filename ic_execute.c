#include "monty.h"
/**
* execute_ic - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: points to monty file
* @content: content of line
* Return: no return
*/
int execute_ic(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_ic}, 
				{"pall", pall_ic}, 
				{"pint", pint_ic},
				{"pop", pop_ic},
				{"swap", swap_ic},
				{"add", add_ic},
				{"nop", nop_ic},
				{"sub", sub_ic},
				{"div", div_ic},
				{"mul", mul_ic},
				{"mod", mod_ic},
				{"pchar", pchar_ic},
				{"pstr", pstr_ic},
				{"rotl", rotl_ic},
				{"rotr", rotr_ic},
				{"queue", queue_ic},
				{"stack", stack_ic},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	channel.args = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack_ic(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
