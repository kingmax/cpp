#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

struct Person
{
	private:
		std::string name;
		std::string addr;
	
	public:
		Person() = default;
		Person(const std::string &n) : name(n){}
		Person(const std::string &n, const std::string &a) : name(n), addr(a){}
		Person(std::istream&); //constructor from cin
		
		std::string getName() const
		{
			return name;
		}
		
		std::string getAddr() const
		{
			return addr;
		}
};

std::istream &input(std::istream &is, Person &p)
{
	is >> p.name >> p.addr;
	return is;
}

std::ostream &output(std::ostream &os, const Person &p)
{
	os << p.getName() << ' ' << p.getAddr();
	return os;
}

//constructor
Person::Person(std::istream &is)
{
	input(is, *this);
}

#endif