#include <stdio.h>
#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 9096

/**
 * read_textfile - a function ...
 * @filename: the list
 * @letters: the number.
 *
 * Return: 1 or 0
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fp, ret;
	char buf[BUF_SIZE + 1];
	size_t cpt = 1;

	if (filename == NULL)
		return (0);

	fp = open(filename, O_RDONLY);

	if (fp == -1)
		return (0);

	while ((ret = read(fp, buf, letters)))
	{
		buf[ret] = '\0';
		printf("%s", buf);
		cpt = cpt + ret;
	}

	close(fp);
	return (cpt - 1);
}

