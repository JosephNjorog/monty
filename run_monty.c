#include "monty.h"
#include <string.h>

void free_tokns(void);
unsigned int tokn_arg_len(void);
int empt_line(char *line, char *delims);
void (*get_opfun(char *opcode))(stack_t**, unsigned int);
int run_mymonty(FILE *script_fd);

/**
 * free_tokns - Frees the global op_toks array of strings.
 */
void free_tokns(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokn_arg_len - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tokn_arg_len(void)
{
	unsigned int toks_len = 0;

	while (op_toks[toks_len])
		toks_len++;
	return (toks_len);
}

/**
 * empt_line - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delims: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int empt_line(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[j]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * get_opfun - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*get_opfun(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", monty_pusher},
		{"pall", monty_paller},
		{"pint", monty_pinter},
		{"pop", monty_poper},
		{"swap", monty_swaper},
		{"add", monty_adder},
		{"nop", monty_noper},
		{"sub", monty_suber},
		{"div", monty_diver},
		{"mul", monty_muler},
		{"mod", monty_moder},
		{"pchar", monty_pcharer},
		{"pstr", monty_pstrer},
		{"rotl", monty_rotler},
		{"rotr", monty_rotrer},
		{"stack", monty_stacker},
		{"queue", monty_queuer},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * run_mymonty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int run_mymonty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0, exit_status = EXIT_SUCCESS;
	unsigned int line_number = 0, prev_tok_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (init_stackar(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (get_inter(line, len, script_fd) != -1)
	{
		line_number++;
		op_toks = (char **)strtow(line, DELIMS);
		if (op_toks == NULL)
		{
			if (empt_line(line, DELIMS))
				continue;
			free_stackar(&stack);
			return (error_maller());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			free_tokns();
			continue;
		}
		op_func = get_opfun(op_toks[0]);
		if (op_func == NULL)
		{
			free_stackar(&stack);
			exit_status = unknown_error(op_toks[0], line_number);
			free_tokns();
			break;
		}
		prev_tok_len = tokn_arg_len();
		op_func(&stack, line_number);
		if (tokn_arg_len() != prev_tok_len)
		{
			if (op_toks && op_toks[prev_tok_len])
				exit_status = atoi(op_toks[prev_tok_len]);
			else
				exit_status = EXIT_FAILURE;
			free_tokns();
			break;
		}
		free_tokns();
	}
	free_stackar(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (error_maller());
	}

	free(line);
	return (exit_status);
}
