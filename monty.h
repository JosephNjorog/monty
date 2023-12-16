#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define STACK 0
#define QUEUE 1
#define DELIMS " \n\t\a\b"

extern char **op_toks;

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

void free_stackar(stack_t **stack);
int init_stackar(stack_t **stack);
int mode_checker(stack_t *stack);
void free_tokns(void);
unsigned int tokn_arg_len(void);
void (*get_opfun(char *opcode))(stack_t**, unsigned int);
int empt_line(char *line, char *delims);

int run_mymonty(FILE *script_fd);
void set_tokn_error(int error_code);

char **strtower(char *str, char *delims);
int is_mydelim(char ch, char *delims);
int get_wrdlength(char *str, char *delims);
int get_wrdcount(char *str, char *delims);
char *get_nxtword(char *str, char *delims);

void monty_pusher(stack_t **stack, unsigned int line_number);
void monty_paller(stack_t **stack, unsigned int line_number);
void monty_pinter(stack_t **stack, unsigned int line_number);
void monty_poper(stack_t **stack, unsigned int line_number);
void monty_swaper(stack_t **stack, unsigned int line_number);
void monty_adder(stack_t **stack, unsigned int line_number);
void monty_noper(stack_t **stack, unsigned int line_number);
void monty_suber(stack_t **stack, unsigned int line_number);
void monty_diver(stack_t **stack, unsigned int line_number);
void monty_muler(stack_t **stack, unsigned int line_number);
void monty_moder(stack_t **stack, unsigned int line_number);
void monty_pcharer(stack_t **stack, unsigned int line_number);
void monty_pstrer(stack_t **stack, unsigned int line_number);
void monty_rotler(stack_t **stack, unsigned int line_number);
void monty_rotrer(stack_t **stack, unsigned int line_number);
void monty_stacker(stack_t **stack, unsigned int line_number);
void monty_queuer(stack_t **stack, unsigned int line_number);

char **strtower(char *str, char *delims);
char *get_inter(int n);


int error_usge(void);
int error_maller(void);
int opener_error(char *filename);
int unknown_error(char *opcode, unsigned int line_number);
int no_error(unsigned int line_number);
int poper_error(unsigned int line_number);
int pinter_error(unsigned int line_number);
int shorter_error(unsigned int line_number, char *op);
int error_diver(unsigned int line_number);
int pcharact_error(unsigned int line_number, char *message);


#endif
