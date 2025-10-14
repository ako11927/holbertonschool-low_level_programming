#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * close_checked - closes a file descriptor or exits with code 100 on failure
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
 * write_all - write exactly n bytes or exit with 99 on failure
 * @fd: destination fd
 * @buf: data buffer
 * @n: bytes to write
 * @name: destination filename (for error message)
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
 * copy_files - copy from @src to @dst using 1,024-byte chunks
 * @src: source path
 * @dst: destination path
 *
 * Exits with:
 * 98 on read error (src), 99 on write/create error (dst), 100 on close error.
 * Creates dst with perms 0664 and truncates if it exists.
 * NOTE: Performs an initial read BEFORE opening dst so read errors take priority.
 */
static void copy_files(const char *src, const char *dst)
{
	int fdf, fdt;
	char buf[BUF_SIZE];
	ssize_t r;

	fdf = open(src, O_RDONLY);
	if (fdf == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	/* Initial read first: ensures forced read() failures map to exit 98 */
	r = read(fdf, buf, BUF_SIZE);
	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		close_checked(fdf);
		exit(98);
	}

	fdt = open(dst, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdt == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst);
		close_checked(fdf);
		exit(99);
	}

	while (r > 0)
	{
		write_all(fdt, buf, r, dst);

		r = read(fdf, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
			close_checked(fdf);
			close_checked(fdt);
			exit(98);
		}
	}

	close_checked(fdf);
	close_checked(fdt);
}

/**
 * main - entry point: cp file_from file_to
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success (exits on errors with 97–100 per spec)
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	copy_files(argv[1], argv[2]);
	return (0);
}
