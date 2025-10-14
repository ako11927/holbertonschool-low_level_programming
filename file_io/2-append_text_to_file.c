#include "main.h"
#include <stdlib.h>

/**
 * _strlen - simple strlen for C89
 * @s: string
 * Return: length of s
 */
static size_t _strlen(const char *s)
{
	size_t n = 0;

	while (s && s[n] != '\0')
		n++;
	return (n);
}

/**
 * append_text_to_file - appends text at end of a file
 * @filename: file name
 * @text_content: NULL-terminated text to append (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t wbytes, total = 0, len;

	if (filename == NULL)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content != NULL)
	{
		len = (ssize_t)_strlen(text_content);
		while (total < len)
		{
			wbytes = write(fd, text_content + total, len - total);
			if (wbytes == -1)
			{
				close(fd);
				return (-1);
			}
			total += wbytes;
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
