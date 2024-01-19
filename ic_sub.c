#include "monty.h"
/**
  *sub_ic - this function performs sustration
  *@head: stack head
  *@counter: line_number
  *Return: no return
 */
void sub_ic(stack_t **head, unsigned int counter)
{
	stack_t *bro;
	int sus, nodes;

	bro = *head;
	for (nodes = 0; bro != NULL; nodes++)
		bro = bro->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(channel.file);
		free(channel.content);
		free_stack_ic(*head);
		exit(EXIT_FAILURE);
	}
	bro = *head;
	sus = bro->next->n - bro->n;
	bro->next->n = sus;
	*head = bro->next;
	free(bro);
}
