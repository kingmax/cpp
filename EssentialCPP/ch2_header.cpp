#include "ch2_header.h"

// 定义一个函数指针
const vector<int>* (*seq_ptr)(int) = fibon_seq;

// 定义头文件中已声明的函数指针数组, 这里仅填充一个值，其它默认为0
const vector<int>* (*seq_arr[seq_cnt])(int) = {
	fibon_seq,
};

// 函数定义
bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int))
{
	if(!check_size(pos))
	{
		cerr << "invalid size: " << pos << endl;
		elem = 0;
		return false;
	}
	
	if(!seq_ptr)
	{
		cerr << "seq_ptr is point to null" << endl;
		exit(-1);
	}
	
	const vector<int> *pv = seq_ptr(pos);
	if(!pv)
	{
		elem = 0;
		return false;
	}
	
	elem = (*pv)[pos-1];
	return true;
}

// 重载
bool seq_elem(int pos, int &elem)
{
	return seq_elem(pos, elem, seq_ptr);
}

const vector<int> *fibon_seq(int size)
{
	static vector<int> vi;

	// 因为是static local object, 函数调用后仍会保留
	// 所以如果多次调用size分别为10, 7, 2时
	// 下面这种写法只需要计算最大size即10那次！
	// 如果有更大的size时，也只会增加后续必需的计算，插入vector
	for(int i = vi.size(); i < size; ++i)
	{
		if(i == 0 || i == 1)
			vi.push_back(1);
		else
			vi.push_back(vi[i-2] + vi[i-1]);
	}
	
	return &vi;
}

void test_it()
{
	cout << "test_it(): " << endl;
	int elem = 0;
	if(seq_elem(10, elem))
		cout << elem << endl;
	else
		cout << "seq_elem(3, elem) return false!" << endl;
}

int main()
{
	cout << "try print const int seq_cnt in header file: "
		 << seq_cnt << endl;
	cout << sizeof(seq_arr) / sizeof(vector<int>*) << endl;	// 6
		 
	const int seq_cnt = 100;
	cout << "try print const int seq_cnt in this file (re-defined): "
		 << seq_cnt << endl;
	cout << sizeof(seq_arr) / sizeof(vector<int>*) << endl; // 6, seq_arr已经先于局部重新定义的const int seq_cnt完成定义，所以长度仍然是6.
		 
	test_it();
	
	return 0;
}