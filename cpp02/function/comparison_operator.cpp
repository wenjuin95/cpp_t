#include <iostream>

class student
{
	public:
		int id;
		std::string name;

		student(int id, std::string name)
		{
			std::cout << "Constructor called" << std::endl;
			this->id = id;
			this->name = name;
		};

		~student()
		{
			std::cout << "Destructor called" << std::endl;
		};

		//comparison operator overloading
		bool operator>(const student &src)
		{
			return (this->id > src.id);
		};
};

int main()
{
	student a(1, "jack");
	student b(2, "jill");
	bool result = a > b;
	if (result == true)
		std::cout << "a.id > b.id: true"<< std::endl;
	else
		std::cout << "a.id > b.id: false"<< std::endl;
	return 0;
}