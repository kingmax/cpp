#include <iostream>
#include <string>
#include "Sales_item.h"

int main()
{
	Sales_item currBook, book;
	std::string isbn;
	if(std::cin >> currBook)
	{
		isbn = currBook.isbn();
		int count = 1;
		
		while(std::cin >> book)
		{
			if(book.isbn() == isbn)
			{
				++count;
			}
			else
			{
				std::cout << isbn << " sold count: " << count << std::endl;
				isbn = book.isbn();
				count = 1;
			}
		}
		
		std::cout << isbn << " sold count: " << count << std::endl;
	}
	return 0;
}