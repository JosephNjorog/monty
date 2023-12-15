#include "monty.h"

/**
 * swaper - swap a TOS item with the one preeding it
 * @stack: pointer to reference to item at TOS
 * @line_number: for the error message
 */
void swaper(stack_t **stack, unsigned int line_number)
{
	stack_t *tos_node, *next_tos;

	if (*stack && (*stack)->prev)
	{
		tos_node = pop2(stack, line_number);
		next_tos = *stack;
		if (struct_state == IN_STACK)
		{
			tos_node->prev = next_tos->prev;
			if (next_tos->prev)
				next_tos->prev->next = tos_node;
			tos_node->next = next_tos;
			next_tos->prev = tos_node;
		}
	}
	else
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * nop - do nothing
 * @stack: pointer to the top of the stack
 * @line_number: line number of opcode from bytecode file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;
}
