#include "monty.h"

/**
 * opcode_push - this is the opcode for push, it calls the push code
 * @**stack: this is the stack
 * @line_numb: this is the line number
 * @*value: the value of the stack
 *
 * Return: it returns void
 */ 

void opcode_push(stack_t **stack, unsigned int line_num, const char *value)
{
	push(stack, line_num, value);
}
