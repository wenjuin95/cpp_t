#include <iostream>

//polymorphism is not supported in C
//1. when write function with "int", you can't write function with "unsigned int". this called "function overloading"
//1. "function overloading" allow us to define multiple function with same name but different parameter

void	print(int i)
{
	std::cout << "int: " << i << std::endl;
}

void	print(unsigned int j)
{
	std::cout << "unsigned int: " << j << std::endl;
}

void	print(int i, unsigned int j)
{
	std::cout << "int: " << i << ", unsigned int: " << j << std::endl;
}

int main()
{
	int i = 10;
	unsigned int j = 100;
	print(i);
	print(j); //this will able to called
	print(i, j);
}