#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE *file;
	char *line = NULL, *token, *saveptr;
	size_t n = 0;
	ssize_t len;

	file = fopen("013.m", "r");
	while ((len = getline(&line, &n, file)) != -1)
	{
		token = strtok_r(line, " \t", &saveptr);
		while (token != NULL)
		{
			printf("%s", token);
			token = strtok_r(NULL, " \t", &saveptr);
		}
	}
}
