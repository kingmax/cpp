//https://www.geeksforgeeks.org/remove-comments-given-cc-program/

// C++ program to remove comments from a C/C++ program 
#include <iostream> 
#include <string>
#include <fstream>
using namespace std; 

string removeComments(string prgm) 
{ 
    int n = prgm.length(); 
    string res; 
  
    // Flags to indicate that single line and multpile line comments 
    // have started or not. 
    bool s_cmt = false; 
    bool m_cmt = false; 
  
  
    // Traverse the given program 
    for (int i=0; i<n; i++) 
    { 
        // If single line comment flag is on, then check for end of it 
        if (s_cmt == true && prgm[i] == '\n') 
            s_cmt = false; 
  
        // If multiple line comment is on, then check for end of it 
        else if  (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/') 
            m_cmt = false,  i++; 
  
        // If this character is in a comment, ignore it 
        else if (s_cmt || m_cmt) 
            continue; 
  
        // Check for beginning of comments and set the approproate flags 
        else if ((prgm[i] == '/' && prgm[i+1] == '/') || (prgm[i] == '-' && prgm[i+1] == '-'))
            s_cmt = true, i++; 
        else if (prgm[i] == '/' && prgm[i+1] == '*') 
            m_cmt = true,  i++; 
  
        // If current character is a non-comment character, append it to res 
        else  res += prgm[i]; 
    } 
    return res; 
}

string removeOnlyMultiComments(const string &prgm)
{
	int n = prgm.length(); 
    string res; 
  
    bool m_cmt = false; 
  
    for (int i=0; i<n; i++) 
    { 
        if (m_cmt == true && prgm[i] == '*' && prgm[i+1] == '/') 
            m_cmt = false,  i++; 
        else if (m_cmt) 
            continue; 
        else if (prgm[i] == '/' && prgm[i+1] == '*') 
            m_cmt = true,  i++; 
        else  res += prgm[i]; 
    } 
    return res; 
}

bool isEmpty(const string &line)
{
	bool ret = true;
	for(auto &c : line)
	{
		if(!isspace(c))
			ret = false;
	}
	return ret;
}

// Driver program to test above functions 
int main(int argc, char* argv[]) 
{ 
    // string prgm = "   /* Test program */ \n"
                  // "   int main()  \n"
                  // "   {           \n"
                  // "      // variable declaration \n"
                  // "      int a, b, c;    \n"
                  // "      /* This is a test  \n"
                  // "          multiline     \n"
                  // "          comment for   \n"
                  // "          testing */      \n"
                  // "      a = b + c;       \n"
                  // "   }           \n"; 
    // cout << "Given Program \n"; 
    // cout << prgm << endl; 
    // cout << " Modified Program "; 
    // cout << removeComments(prgm); 
	
	if(argc < 2)
	{
		cout << "usage: removeComments.exe inSrcFile" << endl;
		return -1;
	}
	
	string filename(argv[1]);
	cout << filename << endl;
	ifstream file(filename);
	string line;
	string lines;
	
	while(getline(file, line))
	{
		if(!line.empty() && !isEmpty(line))
		{
			lines += line;
			lines.push_back('\n');
		}
	}
	file.close();
	cout << lines << endl;
	
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	/* string newLines = removeComments(lines);
	cout << newLines << endl; */
	
	string newLines2 = removeOnlyMultiComments(lines);
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl;
	cout << newLines2 << endl;
	
	string outFile = filename + ".copy";
	ofstream out(outFile);
	if(out)
	{
		out << newLines2;
		out.close();
		cout << "output removeOnlyMultiComments *.copy done" << endl;
		cout << outFile << endl;
	}
	
	
    return 0; 
}