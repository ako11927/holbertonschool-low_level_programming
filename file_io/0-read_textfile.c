#include "main.h"
#include <stdlib.h>
#include <errno.h>

#define CHUNK 1024

/**
 * _write_stdout - write n bytes to STDOUT (handles partial writes/EINTR)
 * @buf: buffer
 * @n: number of bytes
 * Return: n on success, -1 on failure
 */
static ssize_t _write_stdout(const char *buf, ssize_t n)
{
	ssize_t off = 0, w;

	while (off < n)
	{
		w = write(STDOUT_FILENO, buf + off, n - off);
		if (w == -1)
		{
			if (errno == EINTR)
				continue;
			return (-1);
		}
		off += w;
	}
	return (n);
}

/**
 * _read_and_print - read up to @letters bytes from @fd and print them
 * @fd: file descriptor
 * @letters: max bytes to read/print
 * Return: total printed, or 0 on error
 */
static ssize_t _read_and_print(int fd, size_t letters)
{
	char *buf;
	ssize_t r, printed = 0;
	size_t ask;

	buf = malloc(CHUNK);
	if (!buf)
		return (0);

	while (letters)
	{
		ask = (letters < CHUNK) ? letters : CHUNK;
		r = read(fd, buf, ask);
		if (r == 0)
			break;
		if (r == -1)
		{
			if (errno == EINTR)
				continue;
			free(buf);
			return (0);
		}
		if (_write_stdout(buf, r) == -1)
		{
			free(buf);
			return (0);
		}
		printed += r;
		letters -= r;
	}
	free(buf);
	return (printed);
}

/**
 * read_textfile - prints up to @letters bytes of @filename to STDOUT
 * @filename: path
 * @letters: max bytes to print
 * Return: bytes printed, or 0 on error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t printed;

	if (!filename || !letters)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	printed = _read_and_print(fd, letters);

	if (close(fd) == -1)
		return (0);

	return (printed);
}
