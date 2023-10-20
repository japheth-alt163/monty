#include "monty.h"

/**
* main - Entry point to monty
* @argc: Number of arguments
* @argv: an array of arguments
* Return: EXIT_SUCCESS else EXIT_FAIL
*/
int main(int argc, char *argv[])
{
	char *filename;

	FILE *file;

	(void) argv;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	filename = argv[1];
	file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file '%s'\n", filename);
		return (EXIT_FAILURE);
	}

	execute_instructions(file);

	fclose(file);

	return (EXIT_SUCCESS);

}
