#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Sales_data
{
	public:
		string bookNo;
		unsigned sold;
		double revenue;
};

int main()
{
	Sales_data data, *p;
	cout << "sizeof(Sales_data):\t" << sizeof(Sales_data) << endl; //48
	cout << "sizeof(data):\t" << sizeof(data) << endl;//48 (Sales_data)
	cout << "sizeof p:\t" << sizeof p << endl; //8 (int)
	cout << "sizeof *p:\t" << sizeof *p << endl;//48 (Sales_data)
	cout << endl;
	
	cout << "sizeof(string):\t" << sizeof(string) << endl; //32
	cout << "sizeof Sales_data::bookNo:\t" << sizeof Sales_data::bookNo << endl; //32, private member also can access!
	cout << "sizeof data.bookNo:\t" << sizeof data.bookNo << endl; //32, need public!
	cout << "sizeof p->bookNo:\t" << sizeof p->bookNo << endl;     //32, need public!
	
	cout << "\nsizeof Sales_data::bookNo + sizeof Sales_data::sold + sizeof Sales_data::revenue = " << endl;
	cout << sizeof(Sales_data::bookNo) << " + "
		 << sizeof data.sold << " + "
		 << sizeof p->revenue << " = "
		 << sizeof Sales_data::bookNo + sizeof(data.sold) + sizeof(p->revenue) << endl;
	cout << endl;
	
	int arr[] = {1,2,3};
	constexpr size_t size = sizeof(arr) / sizeof(*arr);
	cout << "len(arr) = " << size << endl; //3
	
	return 0;
}