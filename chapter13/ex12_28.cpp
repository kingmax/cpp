#include <string>
#include <iostream>
using namespace std;

class TreeNode //RefClass
{
public:
	TreeNode(const string& s=string()) : value(s), count(new int(1)), left(nullptr), right(nullptr){ cout << "constructor\n"; }
	TreeNode(const TreeNode& p) : value(p.value), count(p.count), left(p.left), right(p.right) { *count++; cout << "copy constructor\n"; }

	TreeNode& operator=(const TreeNode&);
	
	~TreeNode();
	
	void print() const;
	//void set_left(const TreeNode*);
	
private:
	string	value;
	int		*count;
	TreeNode *left;
	TreeNode *right;
};

/* void TreeNode::set_left(const TreeNode* t)
{
	if(left)
		delete left;
	left = t;
	cout << "assignment left node" << endl;
} */

void TreeNode::print() const
{
	cout << "value= " << value << ", used:" << *count << endl
		 << "left node:" << left << ", right node:" << right << endl;
}

TreeNode::~TreeNode()
{
	cout << "in deconstructor" << endl;
	if(--*count == 0)
	{
		delete count;
		delete left;
		delete right;
		cout << "deconstructor release resource" << endl;
	}
}

TreeNode& TreeNode::operator=(const TreeNode& rhs)
{
	++*rhs.count;
	if(--*count == 0)
	{
		delete count;
		delete left;
		delete right;
	}
	
	value = rhs.value;
	count = rhs.count;
	left = rhs.left;
	right = rhs.right;
	
	cout << "copy assignment" << endl;
	return *this;
}

class BinStrTree //ValClass
{
private:
	TreeNode *root;
	
	//ref: https://www.cprogramming.com/tutorial/lesson18.html
	void destroy_tree(TreeNode*);
	void insert(const string&, TreeNode*);
	TreeNode* search(const string&, TreeNode*);
	
public:
	BinStrTree() : root(nullptr){}
	BinStrTree(const BinStrTree& p) : root(new TreeNode(*p.root)){}
	BinStrTree& operator=(const BinStrTree&);
	
	~BinStrTree(){ /* delete root; */ destroy_tree(); }
	
	void insert(const string&);
	void destroy();
	TreeNode* search(const string&);
};

void BinStrTree::destroy_tree(TreeNode* leaf)
{
	if(leaf != NULL)
	{
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

void BinStrTree::insert(const string& s, TreeNode* leaf)
{
	
}

BinStrTree& BinStrTree::operator=(const BinStrTree& rhs)
{
	TreeNode new_root = new TreeNode(*rhs.root);
	delete root;
	root = new_root;
	return *this;
}

int main()
{
	BinStrTree bst;
	TreeNode first("first");
	first.set_left(bst.
	
	return 0;
}