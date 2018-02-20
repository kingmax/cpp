#ifndef __PERSON_H__
#define __PERSON_H__

#include <string>
#include <iostream>

struct Person
{
	std::string name;
	std::string addr;
	
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

#endif