#include "monty.h"

/**
 * add_top - adds new element to top of the stack
 * @stack: pointer to top of the stack
 * @n: element's data
 *
 * Return: pointer to new element
 */
stack_t *add_top(stack_t **stack, int n)
{
	stack_t *new_e;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		(*stack)->next = new_e;
		new_e->prev = (*stack);
		*stack = new_e;
	}

	return (new_e);
}

/**
 * add_queue - adds new element to head of the queue
 * @stack: pointer to head of the queue
 * @n: element's data
 *
 * Return: pointer to new element
 */
stack_t *add_queue(stack_t **stack, int n)
{
	stack_t *new_e, *node;

	new_e = malloc(sizeof(*new_e));
	if (!new_e)
		fprintf(stderr, "Error: malloc failed"), exit(EXIT_FAILURE);
	new_e->n = n, new_e->prev = NULL, new_e->next = NULL;

	if (!stack || !(*stack))
		*stack = new_e;
	else
	{
		node = *stack;
		while (node->next)
			node = node->next;
		node->next = new_e;
		new_e->prev = node;
	}

	return (new_e);
}
