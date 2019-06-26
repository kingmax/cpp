#include <iostream>
#include <string>
#include <vector>
using namespace std;

// int *find(const vector<int> &vec, int value) // Error, const cann't cast to non const
/* const int *find(const vector<int> &vec, int value)
{
	for(int i = 0; i < vec.size(); ++i)
		if(value == vec[i])
			return &(vec[i]);
		
	return 0;
} */

template<typename T>
const T* find(const vector<T> &vec, const T &value)
{
	for(int i = 0; i < vec.size(); ++i)
		if(value == vec[i])
			return &vec[i];
		
	return 0;
} 

int min(int *array);	//这二个函数原型实际上是一样的
int min(int array[24]); //因为数组实际上以第一个元素的地址传入参数

//按传首地址传递, size指示array长度
template<typename T>
const T* find(const T *array, int size, const T &value)
{
	if(!array || size < 1)
		return 0;
	for(int i=0; i<size; ++i)
		if(value == array[i])
			return &array[i]; //array[i] === *(array + i)
	//pointer style: 指针方式	
	for(int i=0; i < size; ++i, ++array)
		if(*array == value)
			return array;
	return 0;
}

//传首地址与末地址传递，标示起止范围
template<typename T>
const T* find(const T *array, const T *sentinel, const T &value);

//pointer style
template<typename T>
const T* find(const T *first, const T *last, const T &v)
{
	if(!first || !last)
		return 0;
	//last指针是指容器最后一个元素的下一地址，实际上已越界
	//所以如果first==last时，指针已经过了所有元素
	for(; first != last; ++first)
		if(*first == value)
			return first;
	return 0;
}

int ia[8] = {1,1,2,3,5,8,13,21};
double da[6] = {1.5, 2.0, 2.5, 3.0, 3.5, 4.0};
string sa[4] = {"pooh", "piglet", "eeyore", "tigger"};

const int *pi = find(ia, ia+8, ia[3]);
const double *pd = find(da, da+6, da[3]);
const string *ps = find(sa, sa+4, sa[3]);

template<typename T>
inline T* begin(const vector<T> &vec)
{
	return vec.empty() ? 0 : &vec[0];
}

template<typename T>
inline T* end(const vector<T> &vec)
{
	return vec.empty() ? 0 : &vec[vec.size()];
}

template<typename T>
const T* find(begin(vector<T>), end(vector<T>), search_value);

int main()
{
	vector<int> v{1,2,3,4,5,6};
	int x = 5;
	const int *p = find(v, x);
	if(p)
		cout << "find value:" << x << ", address:" << p << endl;
	
	vector<string> vs{"a", "b"};
	string s = "c";
	const string *ps = find(vs, s);
	if(ps)
		cout << "find string:" << s << ", address:" << ps << endl;
	else
		cout << "not find string:" << s << ", " << ps << endl;
	
	
	
	return 0;
}
