#include "monty.h"

FILE *openFile(int argc, char *filename)
{
	FILE *file;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", filename);
		exit(EXIT_FAILURE);
	}

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}

	return (file);
}
