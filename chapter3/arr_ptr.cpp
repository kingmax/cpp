#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	string ns[] = {"one", "two", "three"};
	string *p = &ns[0]; //point to first element
	string *p2 = ns; //same *p, point to first element!
	
	int ia[] = {0,1,2,3,4,5,6,7,8,9};
	auto ia2(ia); //ia2 is int ptr, point to first element 0, auto ia2(&ia[0])
	//ia2 = 42; //error, int * <=> int
	/* but decltype(ia) => int[] type */
	decltype(ia) ia3 = {}; //same as: int ia3[10] = {};
	for(int i : ia3)
		cout << i << ' ';
	cout << endl;
	
	//simulate as iterator
	for(int *begin = ia, *end = &ia[10]; begin != end; ++begin)
	{
		*begin *= *begin;
	}
	for(auto i : ia)
		cout << i << ' ';
	cout << endl;
	
	//
	int *beg = begin(ia);
	int *last = end(ia);
	while(beg != last)
		cout << (*(beg++) + 1) << ' ';
	
	constexpr size_t sz = 5;
	int arr[sz] = {1,2,3,4,5};
	int *ip = arr;
	int *ip2 = ip + 5; //end(arr)
	int i_last = *(arr + 4);
	
	int *pe = arr + sz; //end(arr)
	cout << endl << pe << endl << ip2;
	cout << "\npe == ip2? (is end(arr)): " << (pe == ip2) << endl;
	
	int *pe2 = arr + 10; //error, pe2.value undefined
	
	int *b = arr, *e = arr + sz;
	while(b < e)
		cout << *(b++) << ' ';
	cout << endl;
	
	int iarr[] = {0, 2, 4, 6, 8};
	int ia1 = iarr[2];
	int *pia = iarr;
	ia1 = *(pia + 2);
	
	int *pia2 = &iarr[2];
	int j = pia2[1]; //*(pia2 + 1)
	int k = pia2[-2];//*(pia2 - 2) == iarr[0], NOTE:stdlib vector, string only using [unsigned]!!!
	
	return 0;
}