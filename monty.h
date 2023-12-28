#ifndef MONTY_HEADER_FILE
#define MONTY_HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct bus_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifi: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
char *_reallocr(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdinr(char **lineptr, int file);
char  *clean_liner(char *content);
void push_jnm(stack_t **head, unsigned int number);
void pall_jnm(stack_t **head, unsigned int number);
void pint_jnm(stack_t **head, unsigned int number);
int execution_jnm(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack_jnm(stack_t *head);
void pop_jnm(stack_t **head, unsigned int counter);
void swap_jnm(stack_t **head, unsigned int counter);
void add_jnm(stack_t **head, unsigned int counter);
void nope_jnm(stack_t **head, unsigned int counter);
void subract_jnm(stack_t **head, unsigned int counter);
void div_jnm(stack_t **head, unsigned int counter);
void mul_jnm(stack_t **head, unsigned int counter);
void mod_jnm(stack_t **head, unsigned int counter);
void print_char_jnm(stack_t **head, unsigned int counter);
void print_string_jnm(stack_t **head, unsigned int counter);
void rotate_jnm(stack_t **head, unsigned int counter);
void rotate_bottom_jnm(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode_jnm(stack_t **head, int n);
void add_queuer(stack_t **head, int n);
void queue_jnm(stack_t **head, unsigned int counter);
void stack_jnm(stack_t **head, unsigned int counter);

#endif
