#include "monty.h"
/**
* execution_jnm - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int execution_jnm(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t opst[] = {
				{"push", push_jnm}, {"pall", pall_jnm}, {"pint", pint_jnm},
				{"pop", pop_jnm},
				{"swap", swap_jnm},
				{"add", add_jnm},
				{"nop", nope_jnm},
				{"sub", subract_jnm},
				{"div", div_jnm},
				{"mul", mul_jnm},
				{"mod", mod_jnm},
				{"pchar", print_char_jnm},
				{"pstr", print_string_jnm},
				{"rotl", rotate_jnm},
				{"rotr", rotate_bottom_jnm},
				{"queue", queue_jnm},
				{"stack", stack_jnm},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(file);
		free(content);
		free_stack_jnm(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
