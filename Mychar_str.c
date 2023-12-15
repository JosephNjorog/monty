#include "monty.h"

/**
 * pchar - print a char from the stack to the standard output
 * @stack: the top of the stack
 * @line_number: the position of the opcode in the bytecode
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n > 127 || (*stack)->n < 0)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}

/**
 * empty - writes a buffer to stdout and frees it
 * @buffer: given buffer
 *
 * Return: always 0
 */
unsigned int empty(char *buffer)
{
	int i;

	write(STDOUT_FILENO, buffer, 100);
	for (i = 0; i < 100; i++)
		buffer[i] = '\0';
	return (0);
}

/**
 * pstr - prints string at TOS
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void pstr(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	unsigned int i;
	char buffer[100];
	stack_t *tmp;

	i = 0;
	if (stack)
		tmp = *stack;
	else
		tmp = NULL;
	while (tmp)
	{
		/* check if buffer is full */
		if (i >= 100)
			i = empty(buffer);

		/* fill buffer */
		if (tmp->n < 1 || tmp->n > 127)
			break;
		buffer[i++] = tmp->n;

		tmp = tmp->prev;
	}

	buffer[i++] = '\n';
	write(STDOUT_FILENO, buffer, i);
}
