#include "monty.h"
/**
* free_stack_jnm - frees a doubly linked list
* @head: head of the stack
*/
void free_stack_jnm(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
