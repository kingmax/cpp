//p593 typename

template<typename T>
typename T::value_type top(const T &c)
{
	if(!c.empty())
		return c.back();
	else
		return typename T::value_type();
}

//page 594, default template argument
template <typename T, typename F = less<T>>
int compare(const T &v1, const T &v2, F f = F())
{
	if( f(v1, v2) ) return -1;
	if( f(v2, v1) ) return 1;
	return 0;
}

int main()
{
	bool i = ::compare(0, 42);
	
	Sales_data item1(cin), item2(cin);
	bool j = compare(item1, item2, compareIsbn);
}