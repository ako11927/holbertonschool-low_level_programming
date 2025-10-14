#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * close_checked - close fd and handle errors
 * @fd: file descriptor
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
 * main - copy the content of a file to another
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, exits with specific codes on errors
 */
int main(int argc, char **argv)
{
	int fdf, fdt;
	ssize_t rbytes, wbytes;
	char buf[BUF_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fdf = open(argv[1], O_RDONLY);
	if (fdf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}

	fdt = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdt == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
		close_checked(fdf); /* will exit 100 on failure */
		exit(99);           /* not reached, but keeps intent clear */
	}

	while ((rbytes = read(fdf, buf, BUF_SIZE)) > 0)
	{
		ssize_t written = 0;

		while (written < rbytes)
		{
			wbytes = write(fdt, buf + written, rbytes - written);
			if (wbytes == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", argv[2]);
				close_checked(fdf);
				close_checked(fdt);
				exit(99);
			}
			written += wbytes;
		}
	}

	if (rbytes == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		close_checked(fdf);
		close_checked(fdt);
		exit(98);
	}

	close_checked(fdf);
	close_checked(fdt);

	return (0);
}
