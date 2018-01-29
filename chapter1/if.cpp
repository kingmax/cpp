#include <iostream>

int main()
{
	int currVal = 0;
	int val = 0;
	if(std::cin >> currVal)
	{
		int cnt = 1;
		while(std::cin >> val)
		{
			//std::cout << "[befor] currVal = " << currVal << std::endl;
			if(val == currVal)
			{
				++cnt;
			}
			else
			{
				std::cout << currVal << " occurs " << cnt << " times" << std::endl;
				currVal = val;
				cnt = 1;
			}
			//std::cout << "[after] currVal = " << currVal << std::endl << std::endl;
		}
		std::cout << currVal << " occurs " << cnt << " times" << std::endl;
	}
	return 0;
}