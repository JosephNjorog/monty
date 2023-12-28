#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

bus_t bus = {NULL, NULL, NULL, 0};

int main(int argc, char *argv[])
{
    char *content;
    FILE *file;
    size_t size = MAX_LINE_LENGTH;
    size_t len;  /* Move the declaration here */
    stack_t *stack = NULL;
    unsigned int counter = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    bus.file = file;
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    content = (char *)malloc(MAX_LINE_LENGTH);
    if (content == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(content, MAX_LINE_LENGTH, file) != NULL)
    {
        bus.content = content;
        counter++;

        len = strlen(content);
        if (len > 0 && content[len - 1] == '\n')
        {
            content[len - 1] = '\0';
        }

        execution_jnm(content, &stack, counter, file);
    }

    free(content);
    free_stack_jnm(stack);
    fclose(file);
    return (0);
}
