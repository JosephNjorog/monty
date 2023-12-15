#include "monty.h"

/**
 * pusher - pushes data to the top of the stack
 * @stack: pointer to top of the stack
 * @line_number: opcode's line number
 *
 * Return: void
 */
void pusher(stack_t **stack, unsigned int line_number)
{
	int n;
	char *s, *invalid;

	invalid = "";
	/* get value to be pushed to TOS */
	s = strtok(NULL, "\t\n ");
	if (s && invalid)
		n = _atoi(s, &invalid, 10);
	if (!s || *invalid != '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (struct_state == IN_STACK)
		add_to_TOS(stack, n);
	else
		add_to_queue(stack, n);
}

/**
 * paller - prints all elements of a stack
 * @stack: pointer to top of the stack
 * @line_number: opcode's line number
 *
 * Return: void
 */
void paller(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *tmp;

	if (!stack)
		return;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		if (struct_state == IN_STACK)
			tmp = tmp->prev;
		else
			tmp = tmp->next;
	}
}

/**
 * pinter - print an item at the top of the stack
 * @stack: pointer to the reference to the TOS
 * @line_number: to print in an error message
 */
void pinter(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	if (stack && *stack)
		printf("%d\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * poper - removes top element of stack
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void poper(stack_t **stack, unsigned int line_number)
{
	stack_t *popped = pop2(stack, line_number);

	free(popped);
}

/**
 * poper2 - pop an element from the stack and return it
 * @stack: pointer to top of the stack
 * @line_number: the opcode's line number in the bytecode file
 *
 * The function will not free the stack item popped. The caller
 * should free it in on it's own
 *
 * Return: the removed
 */
stack_t *poper2(stack_t **stack, unsigned int line_number)
{
	stack_t *popped, *new_top;

	if (stack && !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (struct_state == IN_STACK)
	{
		new_top = (*stack)->prev;
		if (new_top)
			new_top->next = NULL;
	}
	else
	{
		new_top = (*stack)->next;
		if (new_top)
			new_top->prev = NULL;
	}
	popped = *stack;
	*stack = new_top;
	return (popped);
}
