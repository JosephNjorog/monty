#include "monty.h"

#define BUFFER_SIZE 1024

/**
 * _read - reads content from file
 * @b: buffer to be filled
 * @size: buffer size
 * @fd: file descriptor
 *
 * Return: number of characters read
 */
int _read(char *b, unsigned int size, int fd)
{
	unsigned int j;
	int ret;

	/* clear buffer */
	for (j = 0; j < size; j++)
		b[j] = '\0';

	/* read from file */
	ret = read(fd, b, size);
	if (ret == -1)
		fprintf(stderr, "Error: read failed\n"), exit(EXIT_FAILURE);

	return (ret);
}

/**
 * line_size - counts a line's size of characters
 * @b: buffer
 * @i: starting index
 *
 * Return: number of characters in a line
 */
size_t line_size(char *b, int i)
{
	size_t size;

	size = 0;
	while ((i < BUFFER_SIZE) && b[i] && b[i] != '\n')
		size++, i++;

	return (size);
}

/**
 * fill_b - fills buffer 'b' with a line from 'buffer'
 * @buffer: buffer containing content
 * @i: starting index of buffer
 * @b: pointer to buffer to be filled
 * @n: pointer to b's index
 * @fd: file desciptor
 * @size: b old size
 *
 * Return: new position of i
 */
int fill_b(char *buffer, int i, char **b, size_t *n,
int fd, size_t size)
{
	size_t new_size;

	new_size = 0;
	for (; buffer[i] != '\n'; i++)
	{
		if (i >= BUFFER_SIZE)
		{
			if (_read(buffer, BUFFER_SIZE, fd) == 0)
				break;
			i = 0;
			/* allocate more memory */
			new_size = size + line_size(buffer, i);
			(*b) = _realloc(*b, size, new_size);
			i = -1;
		}
		else
			(*b)[(*n)++] = buffer[i];
	}
	(*b)[(*n)] = '\0';

	return (i);
}

/**
 * _getline - reads an entire line from file
 * @b: buffer to put the line in
 * @n: size of buffer
 * @fd: file descriptor
 *
 * Return: number of read characters | -1 (Failure {including EOF)
 */
ssize_t _getline(char **b, size_t *n, int fd)
{
	static char buffer[BUFFER_SIZE];
	static int i;
	size_t size;

	/* read from file */
	if (i == 0 || i >= BUFFER_SIZE || buffer[i] == '\0')
	{
		if (_read(buffer, BUFFER_SIZE, fd) == 0)
			return (-1);
		i = 0;
	}

	/* free if nececcary */
	if (b && (*b))
		free(*b), *b = NULL;

	/* allocate size of memory */
	size = line_size(buffer, i) + 1;
	*b = malloc(sizeof(char) * size);
	if (!(*b))
		fprintf(stderr, "Error: malloc failed\n"), exit(EXIT_FAILURE);

	/* fill b */
	*n = 0;
	i = fill_b(buffer, i, b, n, fd, size);
	++i;

	return (1);
}
