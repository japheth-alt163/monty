#include "monty.h"

/**
* mod - computes the rest of the division of
* the second top element of the stack
* by the top element of the stack
* @stack: pointer to stack
* @line_number: line number
*/
void mod(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n",
			line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;

	temp = *stack;
	free_temp_mem(temp, stack);
}
