#ifndef __CH2_HEADER_H__
#define __CH2_HEADER_H__

#include <vector>
#include <iostream>
using namespace std;

bool seq_elem(int pos, int &elem);
// bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = 0);
bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int));	// 如果指定了默认参数，则会发生调用不明确(与上面的产生岐义)

const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);

// inline 函数应该放在头文件里
inline bool check_size(int size)
{
	const int max_size = 1024;
	if(size <= 0 || size > max_size)
	{
		cerr << "Oops: requested size is not supported: "
			 << size << " -- can't fulfill request.\n";
		return false;
	}
	return true;
}

// const is file-scope
const int seq_cnt = 6;
// 声明一个函数指针数组, 需要在extern，否则被视为定义
extern const vector<int>* (*seq_arr[seq_cnt])(int);

#endif