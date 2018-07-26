#include <string>
#include <iostream>
using namespace std;

class TreeNode
{
private:
	string value;
	int count;
	TreeNode* left;
	TreeNode* right;
	
public:
	TreeNode() : value(""), count(0), left(nullptr), right(nullptr) {}
	
	TreeNode(const TreeNode& p) : value(p.value), count(p.count), left(p.left), right(p.right) {}
	
	
};