#ifndef __CH2_HEADER_H__
#define __CH2_HEADER_H__

#include <vector>
#include <iostream>
using namespace std;

bool seq_elem(int pos, int &elem);
// bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int) = 0);
bool seq_elem(int pos, int &elem, const vector<int>* (*seq_ptr)(int));	// ���ָ����Ĭ�ϲ�������ᷢ�����ò���ȷ(������Ĳ������)

const vector<int> *fibon_seq(int size);
const vector<int> *lucas_seq(int size);
const vector<int> *pell_seq(int size);
const vector<int> *triang_seq(int size);
const vector<int> *square_seq(int size);
const vector<int> *pent_seq(int size);

// inline ����Ӧ�÷���ͷ�ļ���
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
// ����һ������ָ������, ��Ҫ��extern��������Ϊ����
extern const vector<int>* (*seq_arr[seq_cnt])(int);

#endif