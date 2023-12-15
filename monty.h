#ifndef H
#define H

#define IN_QUEUE 1
#define IN_STACK 0

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int struct_state;

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

void reed_monty(int);
void monty_executer(char *, unsigned int, stack_t **);
char *pata_opc(char *line);
void (*pata_ins(char *opcode))(stack_t **, unsigned int);
void pusher(stack_t **stack, unsigned int line_number);
stack_t *add_top(stack_t **stack, int n);
void paller(stack_t **stack, __attribute__((unused))unsigned int line_number);
ssize_t _getlain(char **, size_t *, int);
void free_stacker(stack_t *stack);
int s_atoi(char *nptr, char **endptr, int base);
void poper(stack_t **, unsigned int);
void ongeza(stack_t **stack, unsigned int line_number);
void pinter(stack_t **stack, __attribute__((unused))unsigned int line_number);
stack_t *poper2(stack_t **stack, unsigned int line_number);
void swaper(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void ondoa(stack_t **stack, unsigned int line_number);
void zidisha(stack_t **stack, unsigned int line_number);
int fill_buf(char *buffer, int i, char **b, size_t *n,
int fd, size_t size)
unsigned int hakuna(char *buffer);
void strprinter(stack_t **stack, unsigned int line_number);
void roteer(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void divaid(stack_t **stack, unsigned int line_number);
void modul(stack_t **stack, unsigned int line_number);
void charprinter(stack_t **stack, unsigned int line_number);
void roteel(stack_t **stack, unsigned int line_number);
void stacker(stack_t **stack, __attribute__((unused))unsigned int line_number);
void queuer(stack_t **stack, __attribute__((unused))unsigned int line_number);
stack_t *add_queue(stack_t **stack, int n);
void *m_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int _soma(char *b, unsigned int size, int fd)
size_t line_saiz(char *b, int i)

#endif /* H */
