#include "ch2_header.h"

// ����һ������ָ��
const vector<int>* (*seq_ptr)(int) = fibon_seq;

// ����ͷ�ļ����������ĺ���ָ������, ��������һ��ֵ������Ĭ��Ϊ0
const vector<int>* (*seq_arr[seq_cnt])(int) = {
	fibon_seq,
};

// ��������
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

// ����
bool seq_elem(int pos, int &elem)
{
	return seq_elem(pos, elem, seq_ptr);
}

const vector<int> *fibon_seq(int size)
{
	static vector<int> vi;

	// ��Ϊ��static local object, �������ú��Իᱣ��
	// ���������ε���size�ֱ�Ϊ10, 7, 2ʱ
	// ��������д��ֻ��Ҫ�������size��10�ǴΣ�
	// ����и����sizeʱ��Ҳֻ�����Ӻ�������ļ��㣬����vector
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
	cout << sizeof(seq_arr) / sizeof(vector<int>*) << endl; // 6, seq_arr�Ѿ����ھֲ����¶����const int seq_cnt��ɶ��壬���Գ�����Ȼ��6.
		 
	test_it();
	
	return 0;
}