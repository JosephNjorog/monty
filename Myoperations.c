#include "monty.h"

/**
 * add - adds top two elements of stack
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void add(stack_t **stack, unsigned int line_number)
{
	/* check if stack has less than 2 elements */
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* add top 2 elements to TOS */
	(*stack)->prev->n += (*stack)->n;
	pop(stack, line_number);
}

/**
 * sub - subtracts top two elements of stack (2TOS - TOS)
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void sub(stack_t **stack, unsigned int line_number)
{
	/* check if stack has less than 2 elements */
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* sub top 2 elements to TOS */
	(*stack)->prev->n -= (*stack)->n;
	pop(stack, line_number);
}

/**
 * mul - multiplies top two elements of stack
 * @stack: pointer to top of the stack
 * @line_number: opcode' line number
 *
 * Return: void
 */
void mul(stack_t **stack, unsigned int line_number)
{
	/* check if stack has less than 2 elements */
	if (stack && (!(*stack) || !(*stack)->prev))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	/* multiply top 2 elements to TOS */
	(*stack)->prev->n *= (*stack)->n;
	pop(stack, line_number);
}

/**
 * divide - perform a division from elements on the stack
 * @stack: pointer to the top of the stack
 * @line_number: the line number of opcode in bytecode file
 *
 * The format will be 1/TOS * Previous TOS
 */
void divide(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = pop2(stack, line_number);
		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = (*stack)->n / top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}

/**
 * modulus - return modulus of division
 * @stack: pointer to the top of the stack
 * @line_number: the line number of opcode in bytecode file
 *
 * The format will be 1/TOS % Previous TOS
 */
void modulus(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (stack && *stack && (*stack)->prev)
	{
		top = pop2(stack, line_number);
		if (top->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*stack)->n = (*stack)->n % top->n;
		free(top);
	}
	else
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
