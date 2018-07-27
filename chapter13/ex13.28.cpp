#include <string>
#include <iostream>
using namespace std;

//Reference Type?
class TreeNode
{
private:
	string value;
	int* refcount;
	TreeNode* left;
	TreeNode* right;
	
public:
	TreeNode() : value(""), refcount(new int(1)), left(nullptr), right(nullptr) {}
	
	TreeNode(const TreeNode& p) : value(p.value), refcount(p.refcount), left(p.left), right(p.right) { ++*refcount; }
	
	TreeNode& operator=(const TreeNode&);
	
	~TreeNode();
};

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
	++*rhs.refcount;
	if(--*refcount == 0)
	{
		delete left;
		delete right;
		delete refcount;
	}
	
	left = rhs.left;
	right = rhs.right;
	value = rhs.value;
	refcount = rhs.refcount;
	
	return *this;
}

TreeNode::~TreeNode()
{
	if(--*refcount == 0)
	{
		delete left;
		delete right;
		delete refcount;
	}
}

//Value Type?
class BinStrTree
{
private:
	TreeNode *root;
	
public:
	BinStrTree() : root(new TreeNode()){ cout << "default constructor\n"; }
	BinStrTree(const BinStrTree& p) : root(new TreeNode(*p.root)){ cout << "copy constructor\n"; }
	BinStrTree& operator=(const BinStrTree&);
	~BinStrTree();
};

BinStrTree::~BinStrTree()
{
	delete root;
}

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs)
{
	cout << "operator = \n";
	TreeNode *_root = new TreeNode(*rhs.root);
	delete root;
	root = _root;
	return *this;
}

int main()
{
	BinStrTree bst;
	BinStrTree bt2(bst);
	BinStrTree bt3 = bst; //copy constructor same as bt3(bst)!
	
	bt3 = bt2; //call operator=
	
	return 0;
}
