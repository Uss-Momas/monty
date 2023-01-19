#include "monty.h"
#include <sys/stat.h>
#include <fcntl.h>

/**
 * main - entry point of our program
 * @ac: the number of arguments
 * @argv: the array of arguments
 * Return: 0 success or EXIT_FAILURE
 */
int main(int ac, char **argv)
{
	int fd;
	ssize_t nchars, r_bytes;
	char *buffer;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	nchars = count_chars(argv[1]);
	buffer = malloc((sizeof(char) * nchars) + 1);
	if (buffer == NULL)
	{
		fprintf(stderr, "Error: cannot allocate memory\n");
		exit(EXIT_FAILURE);
	}
	buffer[nchars] = '\0';
	printf("Number of nchars: %lu\n", nchars);
	r_bytes = read(fd, buffer, nchars);
	if (r_bytes == -1)
		exit(EXIT_FAILURE);
	return (0);
}
