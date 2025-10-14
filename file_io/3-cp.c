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
 * read_first - do the initial read; exit 98 on failure
 * @src: source file name
 * @buf: buffer to fill
 * @fdf: open fd of source
 *
 * Return: number of bytes read (>0) or 0 on EOF
 */
static ssize_t read_first(const char *src, char *buf, int fdf)
{
	ssize_t r = read(fdf, buf, BUF_SIZE);

	if (r == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		close_checked(fdf);
		exit(98);
	}
	return (r);
}

/**
 * copy_loop - write first chunk then continue reading and writing
 * @src: source name
 * @dst: destination name
 * @fdf: source fd
 * @fdt: destination fd
 * @buf: buffer
 * @r: number of bytes already read into buf
 */
static void copy_loop(const char *src, const char *dst,
		      int fdf, int fdt, char *buf, ssize_t r)
{
	while (r > 0)
	{
		write_all(fdt, buf, r, dst);

		r = read(fdf, buf, BUF_SIZE);
		if (r == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n",
				src);
			close_checked(fdf);
			close_checked(fdt);
			exit(98);
		}
	}
}

/**
 * copy_files - copy src to dst using 1,024-byte chunks
 * @src: source path
 * @dst: destination path
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

	/* initial read BEFORE opening dst so read error → exit 98 */
	r = read_first(src, buf, fdf);

	fdt = open(dst, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdt == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dst);
		close_checked(fdf);
		exit(99);
	}

	copy_loop(src, dst, fdf, fdt, buf, r);

	close_checked(fdf);
	close_checked(fdt);
}

/**
 * main - cp file_from file_to
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success (errors exit with 97–100 as specified)
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
