#include "monty.h"
/**
 * pall_jnm -  prints all the values on the stack,
 * starting from the top of the stack.
 * @head: stack head
 * @counter: no used
 * Return: no return
*/
void pall_jnm(stack_t **head, unsigned int counter)
{
	stack_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
