#include <iostream>

/**
 * COPY CONSTRUCTOR
 * 1. create a new object by copy
 * 2. use only at object creation
 * 3. create a new object
 * 4. copy value from another object
*/

class student
{
	private:
		int id;
		std::string name;
	public:
		student(int id, std::string name);

		// Copy constructor
		/***************************/
		/* "student" : class name  */
		/* "src"     : object name */
		/***************************/
		student(const student &src);

		void display();
};

student::student(int id, std::string name)
{
	this->id = id;
	this->name = name;
}

student::student(const student &src)
{
	this->id = src.id;
	this->name = src.name;
}

void student::display()
{
	std::cout << "ID: " << id << std::endl;
	std::cout << "Name: " << name << std::endl;
}

int main()
{
	student a(1, "jack");
	a.display();

	student b(a);
	b.display();
}