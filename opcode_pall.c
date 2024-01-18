#include "monty.h"

/**
 * **stack - this calls the print code
 * @line_numb: this is the line number of the file content
 * @*value: this is the stack value
 *
 * Return: it returns void
 */
void opcode_pall(stack_t **stack, unsigned int line_num, const char *value)
{
	(void)value;

	pall(*stack, line_num);
}
