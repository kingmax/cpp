#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	fstream inOut("copyOut", 
		fstream::ate | fstream::in | fstream::out);
	
	if(!inOut)
	{
		cerr << "Unable to open file!" << endl;
		return EXIT_FAILURE;
	}
	
	auto end_mark = inOut.tellg();	// 当前位置，由于是使用fstream::ate(at the end)打开，所以当前位置即文件尾
	inOut.seekg(0, fstream::beg);	// jump to start
	size_t cnt = 0;
	string line;
	while(inOut && inOut.tellg() != end_mark
		&& getline(inOut, line))
	{
		cnt += line.size() + 1;
		auto mark = inOut.tellg(); //当前位置，为了输出后再退回来
		
		// 将写标记移动到文件尾，输出累计的长度
		inOut.seekp(0, fstream::end);
		inOut << cnt;
		
		// 如果不是最后一行，输出一个空格作为分隔符
		if(mark != end_mark)
			inOut << " ";
		inOut.seekg(mark);	// 回读上次位置
	}
	//定位到文件尾并输出换行符
	inOut.seekp(0, fstream::end);
	inOut << endl;
	
	return 0;
}