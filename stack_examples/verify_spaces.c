#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
	FILE *file;
	char *line = NULL;
	int i, is_only_spaces;
	size_t n = 0;
	ssize_t nread;

	file = fopen("012.m", "r");


	while ((nread = getline(&line, &n, file)) != -1)
	{
		is_only_spaces = 1;
		for (i = 0; i < (int)strlen(line); i++)
		{
			if (!isspace(line[i]))
			{
				is_only_spaces = 0;
				break;
			}
		}

		if (is_only_spaces == 1)
		{
			printf("Line contain Only spaces: %s", line);
		}
		else
			printf("Line contains other than spaces %s", line);
	}

	return (0);
}
