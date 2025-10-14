#include "main.h"

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to file
 * @letters: max number of bytes to read and print
 *
 * Return: actual number of bytes printed, or 0 on any failure
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rcount, wcount, total = 0;
	char *buf;

	if (filename == NULL || letters == 0)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	rcount = read(fd, buf, letters);
	if (rcount == -1)
	{
		free(buf);
		close(fd);
		return (0);
	}

	/* write may write less; loop until all read bytes are written */
	while (total < rcount)
	{
		wcount = write(STDOUT_FILENO, buf + total, rcount - total);
		if (wcount == -1)
		{
			free(buf);
			close(fd);
			return (0);
		}
		total += wcount;
	}

	free(buf);
	if (close(fd) == -1)
		return (0);

	return (total);
}
