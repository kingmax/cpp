#include <iostream>

template <typename T> class ListItem;
template <typename T> class List
{
public:
	List<T>() = default;
	List<T>(const List<T>&);
	List<T>& operator=(const List<T>&);
	// ~List() = default;
	~List<T>() = default;
	void insert(ListItem<T> *ptr, T value);

private:
	ListItem<T> *front, *end;
};

int main()
{
	List<int> li;
	
	return 0;
}