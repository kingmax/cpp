#include <iostream>

int main()
{
	const double pi = 3.14;
	//double *ptr = &pi; //error, pi is const
	const double *cptr = &pi; //ok, point to a const double obj
	//*cptr = 42; //error, *cptr is const, can't changed!
	
	double dval = 3.1415;
	cptr = &dval; //ok, can point to non-const, but can't chang dval
	
	//const point base_type *const var_name
	int errNumber = 0;
	int *const curErr = &errNumber; // a const pointer point to int, always binding to errNumber.address
	const double cd = 3.1;
	const double *const cptr2 = &cd; //const pointer point to const double
	std::cout << errNumber << ' ' << *curErr << ' ' << *cptr2 << std::endl;
	*curErr = 10; //curErr should point to const but not, can change obj.value
	std::cout << errNumber << ' ' << *curErr << ' ' << *cptr2 << std::endl;
	
	return 0;
}