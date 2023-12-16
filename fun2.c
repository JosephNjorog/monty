#include "monty.h"

void monty_adder(stack_t **stack, unsigned int line_number);
void monty_suber(stack_t **stack, unsigned int line_number);
void monty_diver(stack_t **stack, unsigned int line_number);
void monty_muler(stack_t **stack, unsigned int line_number);
void monty_moder(stack_t **stack, unsigned int line_number);

/**
 * monty_adder - Adds the top two values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void monty_adder(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tokn_error(shorter_error(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	monty_poper(stack, line_number);
}

/**
 * monty_suber - Subtracts the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_suber(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tokn_error(shorter_error(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	monty_poper(stack, line_number);
}

/**
 * monty_diver - Divides the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_diver(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tokn_error(shorter_error(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_tokn_error(error_diver(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	monty_poper(stack, line_number);
}

/**
 * monty_muler - Multiplies the second value from the top of
 *             a stack_t linked list by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_muler(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tokn_error(shorter_error(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	monty_poper(stack, line_number);
}

/**
 * monty_moder - Computes the modulus of the second value from the
 *             top of a stack_t linked list  by the top value.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void monty_moder(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		set_tokn_error(shorter_error(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		set_tokn_error(error_diver(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	monty_poper(stack, line_number);
}
