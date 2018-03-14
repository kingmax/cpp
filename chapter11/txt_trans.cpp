#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
using namespace std;

/* 
rule::
brb be right back
k okay?
y why
r are
u you
pic picture
thk thanks!
18r later


test src::
where r u
y dont u send me a pic
k thk 18r

tansform result::
where are you
why dont you send me a picture
okay? thanks! later
*/

bool is_full_empty(const string &s)
{
	bool ret = true;
	for(const auto &c : s)
		if(!isspace(c))
		{
			ret = false;
			break;
		}
	return ret;
}

map<string, string> get_rule_map(ifstream &is)
{
	map<string, string> ret;
	
	string key, content;
	while(is >> key && getline(is, content) /* && !is_full_empty(content) */ /* !content.empty() */)
	{
		cout << "[DEBUG] " << content << endl;
		if(!is_full_empty(content))
			ret[key] = content.substr(1);
	}
	
	return ret;
}

//transfor single word
const string &trans_word(const string &word, const map<string, string> &rule)
{
	/* if(rule.find(word) != rule.cend())
		return rule[word]; //error, [] can not for const???
	else
		return word; */
	auto it = rule.find(word);
	if(it != rule.cend())
		return it->second;
	else
		return word;
}

void trans_file(ifstream &ruleFile, ifstream &srcFile, ofstream &os)
{
	map<string, string> rule = get_rule_map(ruleFile);
	
	string line;
	while(getline(srcFile, line) && !line.empty())
	{
		istringstream iss(line);
		string word;
		bool is_first = true;
		while(iss >> word && !word.empty())
		{
			if(is_first)
				is_first = false;
			else
				os << " ";
			os << trans_word(word, rule);
		}
		os << endl;
	}
}


int main(int argc, char **argv)
{
	string em = "  ";
	cout << (em.empty() ? "yes! empty" : "not empty") << endl;
	cout << (is_full_empty(em) ? "yes! full empty" : "not full empty") << endl;
	
	if(argc != 3)
	{
		cerr << "usage: txt_trans.exe in_rule_file in_src_file" << endl;
		return -1;
	}
	
	ifstream ruleFile(argv[1]);
	if(!ruleFile)
		return -2;
	
	ifstream srcFile(argv[2]);
	if(!srcFile)
		return -3;
	
	string outFileName = string(argv[2]) + ".out";
	ofstream outFile(outFileName);
	if(!outFile)
		return -4;
	
	trans_file(ruleFile, srcFile, outFile);
	ruleFile.close();
	srcFile.close();
	outFile.close();
	
	cout << "trans file finished. -> " << outFileName << endl;
	
	return 0;
}