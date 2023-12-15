#include "monty.h"

/**
 * s_atoi - change an string into an integer and check error
 * @nptr: the string pointer
 * @endptr: pointer to first, non-invalid character
 * @base: the base of conversion
 *
 * Return: the read number or 0
 */
int s_atoi(char *nptr, char **endptr, int base)
{
	if (nptr && *nptr)
		return (strtol(nptr, endptr, base));
	return (0);
}

/**
 * m_realloc - reallocates a memory block using malloc and free
 * @ptr: previous memory pointer
 * @old_size: size of ptr int bytes
 * @new_size: new size in bytes
 * Return: pointer to new allocated memory (Success) | NULL (Failure)
 */
void *m_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *p;
	char *c, *k;
	unsigned int i;

	if (new_size == old_size && ptr)
		return (ptr);
	if (!new_size && ptr)
	{
		free(ptr);
		return (0);
	}
	p = malloc(new_size);
	if (!p)
		return (0);
	if (!ptr)
		return (p);
	i = 0;
	c = p;
	k = ptr;
	while (i < old_size && i < new_size)
	{
		*c++ = *k++;
		i++;
	}
	free(ptr);
	return (p);
}

/**
 * free_stacker - frees stack memory
 * @stack: stack's top element
 *
 * Return: void
 */
void free_stacker(stack_t *stack)
{
	stack_t *next_e;

	if (!stack)
		return;

	if (struct_state == IN_QUEUE)
	{
		next_e = stack->next;
		while (stack)
		{
			free(stack), stack = NULL;
			stack = next_e;
			if (next_e)
				next_e = next_e->next;
		}
		return ;
	}
	next_e = stack->prev;
	while (stack)
	{
		free(stack), stack = NULL;
		stack = next_e;
		if (next_e)
			next_e = next_e->prev;
	}
}
