#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

//https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
bool CheckSubstring(std::string firstString, std::string secondString){
    if(secondString.size() > firstString.size())
        return false;

    for (int i = 0; i < firstString.size(); i++){
        int j = 0;
        if(firstString[i] == secondString[j]){
            while (firstString[i] == secondString[j] && j < secondString.size()){
                j++;
                i++;
            }

            if (j == secondString.size())
                    return true;
        }
    }
    return false;
}

bool contains(const string &s, const string &k)
{
	string::size_type n = s.size(), sz = k.size();
	if(n < sz)
		return false;
	
	for(string::size_type i = 0; n-i >= sz; ++i)
	{
		if(s.substr(i, sz) == k)
			return true;
	}
	
	return false;
}

int main(int argc, char **argv)
{
	if(argc != 3)
	{
		cerr << "usage: in_out_txt.exe in_file keyword" << endl;
		return -1;
	}
	
	ifstream fp(argv[1]);
	string keyword(argv[2]);
	if(!fp)
	{
		cerr << "Cloundn't open file: " << argv[1] << endl;
		return -2;
	}
	
	string out = string(argv[1]) + ".out";
	ofstream fp2(out);
	if(!fp2)
	{
		cerr << "clound not create out file: " << out << endl;
		return -3;
	}
	
	//vector<string> lines;
	while(!fp.eof())
	{
		string line;
		getline(fp, line);
		if( /* contains(line, keyword) */ /* CheckSubstring(line, keyword) */ line.find(keyword) != string::npos )
			//lines.push_back(line);
			fp2 << line << endl;
	}
	fp.close();
	fp2.close();
	
	/* cout << "process finished, ready output: " << out << endl;
	ofstream fp2(out);
	if(!fp2)
	{
		cerr << "clound not create out file: " << out << endl;
		return -3;
	}
	for(const auto &line : lines)
		fp2 << line << endl;
	fp2.close(); */
	
	cout << "finished!" << endl;
	
	return 0;
}
