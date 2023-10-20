#include "monty.h"

/* Data structure holding pairs of opcode */
static instruction_t instructions[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{"add", add},
	{"nop", nop},
	{"sub", sub},
	{"div", _div},
	{"mul", mul},
	{"mod", mod},
	{"pchar", pchar},
	{"pstr", pstr},
	{"stack", stack},
	{"queue", queue},
	{NULL, NULL}
};

/**
 * free_mem - Free memory.
 * @curr: - Current stack.
 */
void free_mem(stack_t *curr)
{
	while (curr != NULL)
	{
		stack_t *temp = curr;

		curr = curr->next;
		free(temp);
	}
}

/**
 * execute_instructions - Executes monty bytecode instructions.
 * @file: File pointer.
 */
void execute_instructions(FILE *file)
{
	char buffer[256];
	int line_number = 1, i, flag = 0;
	stack_t *curr;
	stack_t *stack = NULL;

	while (fgets(buffer, sizeof(buffer), file))
	{
		char *opcode;

		buffer[strcspn(buffer, "\n")] = '\0'; /* Remove white space */
		opcode = strtok(buffer, " "); /* Tokenize instruction */

		if (opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			fprintf(stderr, "L%u: unknown instruction\n",
				line_number);
			exit(EXIT_FAILURE);
		}
		line_number++;
	}
	curr = stack;
	free_mem(curr);
}
