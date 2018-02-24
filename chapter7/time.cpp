//http://zh.cppreference.com/w/cpp/chrono
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
using namespace std;

long fibonacci(unsigned n)
{
	if(n < 2)
		return n;
	return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
	auto start = std::chrono::system_clock::now();
	std::cout << "f(42) = " << fibonacci(42) << std::endl;
	auto end = std::chrono::system_clock::now();
	
	std::chrono::duration<double> elapsed_seconds = end - start;
	std::time_t end_time = std::chrono::system_clock::to_time_t(end);
	
	std::cout << "finished computation at " << std::ctime(&end_time)
			  << "elapsed time: " << elapsed_seconds.count() << "s\n";
			  
	cout << endl;
	time_t t = time(nullptr);
	string str = string(asctime(localtime(&t)));
	cout << str << endl << t << endl;
	
	return 0;
}