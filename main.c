#include "monty.h"

/**
 * main - simple interpreter for Monty 0.98 scripting language
 * @ac: arguments' count
 * @av: arguments' vector
 * Description: Monty 0.98 is a scripting language,
 * that is first compiled into Monty byte codes (Just like Python).
 * It relies on a unique stack, with specific instructions to manipulate it.
 * The goal is to create an interpreter for Monty ByteCodes files.
 *
 * Return: 0 (Success) | exits with EXIT_FAILURE (Failure)
 */
int main(int ac, char **av)
{
	int fd;

	/* initialize state to stack*/
	struct_state = IN_STACK;
	/* check usage */
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* open file if possible */
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	/* execute instructions */
	read_monty(fd);

	/* close file and end the program */
	close(fd);
	return (0);
}
