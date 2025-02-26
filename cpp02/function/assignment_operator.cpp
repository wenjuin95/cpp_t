#include <iostream>

/**
 * ASSIGNMENT OPERATOR
 * 1. copy when the object is already created (if not can't copy)
 * 2. used only with existing object
 * 3. it have self assignment check [ if (this != &src) ]
*/

class student
{
	private:
	public:
		int id;
		std::string name;
		student(){
			std::cout << "Default constructor" << std::endl;
		};

		student(int id, std::string name)
		{
			std::cout << "Constructor called" << std::endl;
			this->id = id;
			this->name = name;
		};

		//assignment operator overloading
		student &operator=(const student &src)
		{
			std::cout << "Copy assignment operator called" << std::endl;
			this->id = src.id + 1;
			this->name = "hello " + src.name;
			return (*this);
		};
};

int main()
{
	student a(1, "jack");
	std::cout << "id: " << a.id << std::endl;
	std::cout << a.name << std::endl;
	student c;
	c = a;
	std::cout << "id: " << c.id << std::endl;
	std::cout << c.name << std::endl;
	return 0;
}