#include "monty.h"

/**
 * monty_executer - executes an instruction of Monty bytecode
 * @instruction: bytecode instruction
 * @ln: line number
 * @top: pointer to top of the stack
 *
 * Return: void
 */
void monty_executer(char *instruction, unsigned int ln, stack_t **top)
{
	char *opcode;
	void (*f)(stack_t **, unsigned int);

	opcode = get_opcode(instruction);
	if (opcode && opcode[0] != '#')
	{
		f = get_instruction(opcode);
		if (!f)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", ln, opcode);
			exit(EXIT_FAILURE);
		}
		/* execute bytecode instruction */
		f(top, ln);
	}
}
