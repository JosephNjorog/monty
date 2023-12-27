#include "monty.h"
/**
 * print_string_jnm - prints the string starting at the top of the stack,
 * followed by a new
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void print_string_jnm(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	for (;h;)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
