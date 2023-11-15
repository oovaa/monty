#define _GNU_SOURCE
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

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    stream = fopen(filename, "r");
    if (stream == NULL)
    {
        fprintf(stderr, "Error: Unable to open file stream\n");
        exit(EXIT_FAILURE);
    }

    return stream;
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
	int capacity = 100;
	char **arr = malloc(sizeof(*arr) * capacity);
	if (!arr)
	{
		fclose(stream);
		fprintf(stderr, "Error: malloc failed\n");
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

/* 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *filename = argv[1];
    FILE *stream = openFile(argc, filename);

    char *line;
    while ((line = readfile(stream)) != NULL)
    {
        printf("%s\n", line);
    }

    fclose(stream);

    return 0;
}
 */
