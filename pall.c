#include "monty.h"

/**
* pall - print elements of the stack
* @stack: pointer to the stack
* @line_number: unused variable
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	(void) line_number;

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}
