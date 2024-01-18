#ifndef MONTY_H
#define MONTY_H
#define STACK_MAX_SIZE 100
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <ctype.h>
#include <unistd.h>
#include <fcntl.h>
#define MAX_LINE_LENGTH 1000
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * channel_s - conveys arguments from file for opcode calls mapping file contents
 * @args: file content values
 * @file: points to the specified monty file with .m extension
 * @content: the content in the file
 * @changestack: signals the change of stack to queue
 * 
 * Return: it returns arguments, file in lin contents of a monty file
 */
typedef struct channel_s
{
	char *args;
	FILE *file;
	char *content;
	int changestack;
} channel_t;
extern channel_t channel;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void push_ic(stack_t **head, unsigned int counter);
void pall_ic(stack_t **head, unsigned int counter);
void pint_ic(stack_t **head, unsigned int counter);
int execute_ic(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack_ic(stack_t *head);
void pop_ic(stack_t **head, unsigned int counter);
void swap_ic(stack_t **head, unsigned int counter);
void add_ic(stack_t **head, unsigned int counter);
void nop_ic(stack_t **head, unsigned int counter);
void sub_ic(stack_t **head, unsigned int counter);
void div_ic(stack_t **head, unsigned int counter);
void mul_ic(stack_t **head, unsigned int counter);
void mod_ic(stack_t **head, unsigned int counter);
void pchar_ic(stack_t **head, unsigned int counter);
void pstr_ic(stack_t **head, unsigned int counter);
void rotl_ic(stack_t **head, unsigned int counter);
void rotr_ic(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode_ic(stack_t **head, int n);
void addqueue_ic(stack_t **head, int n);
void queue_ic(stack_t **head, unsigned int counter);
void stack_ic(stack_t **head, unsigned int counter);
char *read_line(FILE *file);
#endif
