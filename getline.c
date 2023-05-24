#include "shell.h"

/**
 * read_buffer - a fun to read buffer
 * @buffer: buffer
 * @buffer_index: new size
 * @chars_read: characters read
 * @stream: stdin
 * Return: chars read
 */
ssize_t read_buffer(char *buffer, size_t *buffer_index,
		ssize_t *chars_read, FILE *stream)
{
	if (*buffer_index >= (size_t)*chars_read)
	{
		*chars_read = read(fileno(stream), buffer, 1024);
		if (*chars_read <= 0)
			return (-1);
		*buffer_index = 0;
	}
	return (*chars_read);
}

/**
 * _getline - a fun to get the line
 * @lineptr: buffer
 * @n: new size
 * @stream: stdin
 * Return: new size
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	static char buffer[1024];
	static size_t buffer_index;
	static ssize_t chars_read;
	ssize_t total_chars_read = 0, line_length = 0;
	ssize_t chars_read_result;
	char *resized_line;
	size_t newline_index, i;

	buffer_index = 0;
	chars_read = 0;
	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	chars_read_result = read_buffer(buffer,
			&buffer_index, &chars_read, stream);
	if (chars_read_result == -1)
		return (-1);
	newline_index = buffer_index;
	while (newline_index < (size_t)chars_read &&
			buffer[newline_index] != '\n')
		newline_index++;
	line_length = newline_index - buffer_index;
	if (*n < (size_t)(line_length + 1))
	{
		*n = line_length + 1;
		resized_line = (char *)realloc(*lineptr, *n);
		if (resized_line == NULL)
			return (-1);
		*lineptr = resized_line;
	}
	for (i = 0; i < (size_t)line_length; i++)
		(*lineptr)[i] = buffer[buffer_index++];
	(*lineptr)[line_length] = '\0';
	if (newline_index < (size_t)chars_read)
		buffer_index++;
	total_chars_read = line_length + 1;
	return (total_chars_read);
}
