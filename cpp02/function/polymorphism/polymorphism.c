#include <stdio.h>

void	print(int i)
{
	printf("int: %d\n", i);
}

void	print(unsigned int j)
{
	printf("unsigned int: %u\n", j);
}

int main()
{
	int i = 10;
	unsigned int j = 100;
	print(i);
	print(j); //this will get error of comflict function name
}