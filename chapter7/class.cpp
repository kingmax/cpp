#include "class.h"
using namespace std;

int main()
{
	cout << "Enter: isbn sold revenue" << endl;
	Books_data total(cin);
	
	output(cout, total) << endl;
	
	return 0;
}