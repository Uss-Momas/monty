#include <stdio.h>
/**
 * count_chars - counts the number of characters of a file
 * @filename: name of the file
 * Return: -1 on failure or total number of chars
 */
int count_chars(char *filename)
{
	FILE *file;
	int total = 0;
	char c;

	file = fopen(filename, "r");

	if (file == NULL)
	{
		printf("Error");
		return (1);
	}

	while ((c = fgetc(file)) !=  EOF)
	{
		total++;
	}
	return (total);
}
