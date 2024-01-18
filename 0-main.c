#include <stdio.h>
#include "monty.h"
#include <stdlib.h>
#include <string.h>
/**
 * main - prints the functions
 * 
 * Return: it always return success (0)
 */
int main(void)
{
	stack_t *use_stack = NULL;

	instruction_t instructions[] = {
		{"push", opcode_push},
		{"pall", opcode_pall},
	};
	size_t num_instructions = sizeof(instructions) / sizeof(instructions[0]);

	execution("byteodes/00.m", &use_stack, instructions, num_instructions);

	return 0;
}
