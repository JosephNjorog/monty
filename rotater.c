#include "monty.h"

/**
 * roteel - rotate the linkedlist one item at a time
 * @stack: pointer to the top of the stack
 * @line_number: the position of the opcode in the bytecode
 */
void roteel(stack_t **stack, unsigned int line_number)
{
	stack_t *node, *popped;

	if (stack && *stack && (*stack)->prev)
	{
		popped = pop2(stack, line_number);
		node = *stack;
		while (node->prev)
			node = node->prev;
		node->prev = popped;
		popped->next = node;
		popped->prev = NULL;
	}
}

/**
 * roteer - rotates stack to the bottom
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void roteer(stack_t **stack, __attribute__((unused))unsigned int line_number)
{
	stack_t *last;

	if (!stack || !(*stack) || !(*stack)->prev)
		return;

	/* get last element */
	last = *stack;
	while (last && last->prev)
		last = last->prev;

	/* rotate */
	last->next->prev = NULL;
	last->prev = *stack;
	last->next = NULL;
	(*stack)->next = last;

	/* change TOS */
	*stack = last;
}
