#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * close_checked - closes a file descriptor, exiting on failure.
 * @fd: file descriptor to close
 *
 * Exits with code 100 and prints the required error message on stderr
 * if close(2) fails.
 */
static void close_checked(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * write_all - writes exactly n bytes or exits with code 99 on failure.
 * @fd: destination file descriptor
 * @buf: buffer to write from
 * @n: number of bytes to write
 * @name: destination filename for error message
 */
static void write_all(int fd, const char *buf, ssize_t n, const char *name)
{
	ssize_t off = 0, w;

	while (off < n)
	{
		w = write(fd, buf + off, n - off);
		if (w == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
			exit(99);
		}
		off += w;
	}
}

/**
 * main - copies the content of one file to another using system calls only.
 * @argc: argument count
 * @argv: argument vector (file_from, file_to)
 *
 * Return: 0 on success; exits with codes 97, 98, 99, or 100 on failure.
 */
int main(int argc, char **argv)
{
	int fdf, fdt;
	char buf[BUF_SIZE];
	ssize_t r;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	/* Open source */
	fdf = open(argv[1], O_RDONLY);
	if (fdf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	/* First read BEFORE opening destination so read errors take precedence */
	r = read(fdf, buf, BUF_SIZE);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_checked(fdf);
		exit(98);
	}

	/* Open destination only after confirming we can read */
	fdt = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdt == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_checked(fdf);
		exit(99);
	}

	/* Write the first chunk already read, then continue the loop */
	while (r > 0)
	{
		write_all(fdt, buf, r, argv[2]);

		r = read(fdf, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
			close_checked(fdf);
			close_checked(fdt);
			exit(98);
		}
	}

	close_checked(fdf);
	close_checked(fdt);
	return (0);
}
