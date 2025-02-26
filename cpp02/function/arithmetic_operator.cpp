#include <iostream>

//example of "+" operator for class ( if you remove the operator overloading function, it will give error)

class math
{
	public:
		int nb;

	math(int nb)
	{
		std::cout << "constructor called" << std::endl;
		this->nb = nb;
	}

	math operator+(const math &src) const
	{
		std::cout << "arithmetic operator called" << std::endl;
		return (math(this->nb + src.nb)); //here will call the constructor again
	}
};

int main()
{
	math a(1);
	math b(2);
	std::cout << ( a+b ).nb << std::endl;
	return 0;
}