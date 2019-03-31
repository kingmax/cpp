#include <iostream>
#include <vector>
#include <string>
using namespace std;

const vector<int> *fibon_seq(int size){ static vector<int> v{1,2,3}; return &v; }
const vector<int> *lucas_seq(int size){ static vector<int> v{4,5,6}; return &v; }
const vector<int> *pell_seq(int  size){ static vector<int> v{7,8,9}; return &v; }
const vector<int> *triangSeq(int size){ static vector<int> v; return &v; }
const vector<int> *squareSeq(int size){ static vector<int> v; return &v; }
const vector<int> *pent_seq( int size){ static vector<int> v; return &v; }



// a function pointer point to a function which returned const vector<int>*
// init it is 0 which means point to nothing
bool fibon_elem(int pos, int &elem, 
	const vector<int>* (*pDelegate)(int /*size*/) = 0)
{
	if(!pDelegate)
	{
		cerr << "Internal Error: pDelegate is set to null!";
		exit(-1);
	}
	
	const vector<int> *pvec = pDelegate(pos);
	
	if(!pvec)
	{
		elem = 0;
		return false;
	}
	
	elem = (*pvec)[pos-1];
	return true;
}

enum ns_type
{
	ns_fibon, ns_lucas, ns_pell,
	ns_triang, ns_square, ns_pent
};

int main()
{
	cout << "just test" << endl;
	
	// define function pointer: seq_ptr
	const vector<int>* (*seq_ptr)(int) = 0;
	
	const vector<int>* (*seq_array[])(int) = {
		fibon_seq, lucas_seq, pell_seq,
		triangSeq, squareSeq, pent_seq
	};
	
	int seq_index = 0;
	bool next_seq = false;
	while(next_seq)
	{
		seq_ptr = seq_array[++seq_index];
		// ...
	}
	
	return 0;
}
