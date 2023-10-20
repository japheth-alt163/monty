#include "monty.h"

/**
* is_integer - check if a string contains a valid int
* @str: str to check
* Return: true else false
*/

bool is_integer(const char *str)
{
	if (str == NULL || *str == '\0')
		return (false);

	if (*str == '+' || *str == '-')
		str++;

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}

	return (true);
}

/**
* push - Add an element to the top of the stack.
* @stack: stack structure.
* @value: Element to add on top of the stack.
*/
void push(stack_t **stack, unsigned int value)
{
	stack_t *new_node;
	int atoi_value;

	char *arg = strtok(NULL, " ");

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", value);
		exit(EXIT_FAILURE);
	}

	atoi_value = atoi(arg);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi_value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}
	*stack = new_node;

}
