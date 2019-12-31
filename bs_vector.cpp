#include "std_lib_facilities.h"

int main()
{
	vector<double> temps;
	double temp;
	while(cin >> temp)
		temps.push_back(temp);
	
	for(auto &item : temps)
		cout << item << ", ";
	
	double sum = 0;
	for(auto &i : temps) sum += i;
	cout << "\nAverage temperature: " << sum / temps.size() << endl;
	
	sort(temps.begin(), temps.end());
	cout << "Median temperatue: " << temps[temps.size()/2] << endl;
	
	for(auto &i : temps) cout << i << ", ";
	
	return 0;
}