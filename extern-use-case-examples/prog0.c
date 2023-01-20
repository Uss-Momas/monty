#include "prog1.h"
#include "file3.h"
#include <stdio.h>

int main(void)
{
	global_variable = 140;
	print_it();
	use_it();
	printf("Increment: %d\n", increment());
	use_it();
	return (0);
}
