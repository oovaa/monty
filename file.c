#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "monty.h"

/**
 * openFile - opens a the monty file
 * @argc: the number of arguments
 * @filename: the name of the file to be opened
 *
 * Return: a file pointer to the stream
 */

FILE *openFile(int argc, char *filename)
{
	FILE *stream;
	int fd = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	stream = fdopen(fd, "r");
	return (stream);
}

/**
 * readfile - reads the file required line by line
 * @stream: a file pointer of the stream of the file required
 *
 * Return: a string of the line read
 */

char *readfile(FILE *stream)
{
	size_t len = 1024;
	char *str = malloc(1024);
	int input_len;

	if (!str)
	{
		fclose(stream);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	input_len = getline(&str, &len, stream);
	if (input_len == -1)
	{
		free(str);
		return (NULL);
	}
	str[input_len - 1] = '\0';
	return (str);
}

/**
 * toker - tokonizes a string
 * @str: the string to be tokanized
 *
 * Return: an array of tokens
 */

char **toker(char *str, FILE *stream)
{
	int i = 0;
	char **arr = malloc(sizeof(*arr) * 10);
	if (!arr)
	{
		fclose(stream);
		fprintf(stderr, "USAGE: monty file");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		if (i == 0)
			arr[i] = strtok(str, " \t");
		else
			arr[i] = strtok(NULL, " \t");
		if (arr[i] == NULL)
			break;
		i++;
	}
	return (arr);
}
