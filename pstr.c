#include "monty.h"

/**
* pstr - prints the string starting at the top of the stack
* @stack: pointer to stack
* @line_number: Line number
*
*/
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *curr;

	(void)line_number;

	curr = *stack;

	while (curr != NULL && curr->n != 0 &&
		curr->n >= 0 && curr->n <= 127)
	{
		printf("%c", curr->n);
		curr = curr->next;
	}

	printf("\n");
}
