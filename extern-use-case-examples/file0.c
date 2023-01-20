#include "file3.h"
#include <stdio.h>

int global_variable;

void print_it(void)
{
	printf("Global var: %d\n", global_variable);
}
