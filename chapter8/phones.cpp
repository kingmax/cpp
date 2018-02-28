//exercise 8.13
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct PhoneInfo
{
	string name;
	vector<string> phones;
};

bool valid(const string &phoneNumber)
{
	for(const auto &c : phoneNumber)
		if(!isdigit(c))
			return false;
	return true;
}

string format(const string &phoneNumber)
{
	return "086-" + phoneNumber;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cerr << "usage: phones.exe in_file" << endl;
		return -1;
	}
	
	vector<PhoneInfo> phoneBook;
	ifstream input(argv[1]);
	if(!input)
	{
		cerr << "Cloudn't open file: " << argv[1] << endl;
		return -2;
	}
	
	string line;
	while(!input.eof() && getline(input, line))
	{
		if(line.empty())
			continue;
		istringstream iss(line);
		PhoneInfo record;
		iss >> record.name;
		string phoneNumber;
		while(iss >> phoneNumber)
			record.phones.push_back(phoneNumber);
		phoneBook.push_back(record);
	}
	input.close();
	
	cout << "\nread data from file finished." << endl;
	cout << phoneBook.size() << endl;
	cout << "ostringstream output:" << endl;
	
	for(const auto &entry : phoneBook)
	{
		ostringstream formatted, badNumbers;
		for(const auto &phone : entry.phones)
		{
			if(!valid(phone))
				badNumbers << ' ' << phone;
			else
				formatted << ' ' << format(phone);
		}
		
		if(badNumbers.str().empty())
			cout << entry.name << ' ' << formatted.str() << endl;
		else
			cerr << "phoneNumber ERROR @ " << entry.name << ", invalid number(s): " << badNumbers.str() << endl;
		cout << endl;
	}
	
	
	return 0;
}