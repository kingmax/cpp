#include <iostream>

int main()
{
	char q = 'q';
	q <<= 6;
	std::cout << q << std::endl; //@
	std::cout << ('q' << 6) << std::endl; //7232 <= 0001 1100 0100 0000
	std::cout << (char(64)) << std::endl; //64   <= 0100 0000
	std::cout << std::endl;
	
	//quiz
	unsigned long quiz = 0; //32 bit
	
	//set student27 to true (bit = 1)
	quiz |= 1UL << 27;    // 0 | 0000 1000  0000 0000  0000 0000  0000 0000
	std::cout << quiz << std::endl;
	
	//set student27 to false (bit = 0)
	quiz &= ~(1UL << 27); // 0 & 1111 0111  1111 1111  1111 1111  1111 1111
	std::cout << quiz << std::endl;
	
	//get
	quiz |= 1UL << 27; //set to true
	bool status = quiz & (1UL << 27); //true or false
	std::cout << status << std::endl << std::endl;
	
	//4.27
	unsigned long ul_1 = 3, ul_2 = 7;
	std::cout << (ul_1 & ul_2) << std::endl; // 0011 & 0111 = 0011 (3)
	std::cout << (ul_1 | ul_2) << std::endl; // 0011 | 0111 = 0111 (7)
	std::cout << (ul_1 && ul_2) << std::endl; //1 (true)
	std::cout << (ul_1 || ul_2) << std::endl; //1 (true)
	
	return 0;
}