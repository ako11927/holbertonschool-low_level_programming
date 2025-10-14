#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024

/**
 * close_checked - close fd or exit 100 on error
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
 * write_all - write exactly n bytes or exit 99 on failure
 * @fd: destination fd
 * @buf: buffer
 * @n: bytes to write
 * @name: dest filename (for message)
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
 * read_chunk - read up to BUF_SIZE; exit 98 on failure
 * @src: source file name (for message)
 * @fdf: source fd
 * @fdt: dest fd, or -1 if not opened yet
 * @buf: buffer to fill
 * Return: number of bytes read, or 0 on EOF
 */
static ssize_t read_chunk(const char *src, int fdf, int fdt, char *buf)
{
	ssize_t r = read(fdf, buf, BUF_SIZE);

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		close_checked(fdf);
		if (fdt != -1)
			close_checked(fdt);
		exit(98);
	}
	return (r);
}

/**
 * copy_files - copy src to dst using 1,024-byte chunks
 * @src: source path
 * @dst: destination path
 *
 * Note: does an initial read before opening dst so read errors exit with 98.
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

	/* initial read BEFORE opening dst so read error -> exit 98 */
	r = read_chunk(src, fdf, -1, buf);

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
		r = read_chunk(src, fdf, fdt, buf);
	}

	close_checked(fdf);
	close_checked(fdt);
}

/**
 * main - cp file_from file_to
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success (errors exit with 97-100)
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
