#include "monty.h"

void freeAll_and_exit(FILE *stream, char *input_str , char **arg, stack_t *head)
{
				fclose(stream);
				free(input_str);
				free(arg);
/* do we need to create free array for arg? */
				free_stack(head);
				head = NULL;
				exit(EXIT_FAILURE);
}

