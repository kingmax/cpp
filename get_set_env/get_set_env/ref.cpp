// https://www.cnblogs.com/findumars/p/6379856.html

//#include "stdafx.h"
//#include "addPath.h"
//
//#define _AFXDLL
//#include <afxwin.h>
//#include <iostream>
//#include <tchar.h>  
//#include <afx.h>
//#include <afxpriv.h>
//using namespace std;
//
//int AddPath(char * strPath)
//{
//	HKEY hkResult;//键的句柄
//	LPCTSTR environmentKey = _T("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment");
//	//HKEY_CURRENT_USER   HKEY_LOCAL_MACHINE
//	//LPCTSTR environmentKey =_T("Environment");
//	if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, environmentKey, 0, KEY_SET_VALUE | KEY_READ, &hkResult)) //打开键environment     
//	{
//		MessageBox(NULL, _T("访问注册表出错！\n请使用管理员帐户执行本程序！"), _T("ERROR"), MB_ICONERROR);
//		return 0;
//	}
//	DWORD BufferSize = 8192;   //数据长度   
//	DWORD cbData;    ////数据长度   
//	DWORD dwRet;
//	VOID* PerfData = malloc(BufferSize);//数据存放地址     
//	cbData = BufferSize;
//
//	LPCTSTR myVariable = _T("PATH");//环境变量    
//	dwRet = RegQueryValueEx(hkResult, myVariable, NULL, NULL, (LPBYTE)PerfData, &cbData); //读取某子键下特定名称的值       
//	while (dwRet == ERROR_MORE_DATA)
//	{
//		BufferSize += 4096;
//		PerfData = realloc(PerfData, BufferSize);
//		cbData = BufferSize;
//		dwRet = RegQueryValueEx(hkResult, myVariable, NULL, NULL, (LPBYTE)PerfData, &cbData);
//	}
//	//MessageBox(NULL,(LPCTSTR)PerfData,_T("我的系统变量Path"),MB_OK);
//
//	if (dwRet == ERROR_SUCCESS)//名称不存在时，添加这个名称并设定其值    
//	{
//		//判断是否存在myValue  
//		if (IsPathExist(PerfData, strPath))
//		{
//			//MessageBox(NULL,_T("环境变量已经存在！"),_T("信息"),MB_OK);
//			RegCloseKey(hkResult);//释放键句柄 
//			free(PerfData);
//			return 1;
//		}
//
//		LPTSTR myValueEx = new TCHAR[strlen(strPath) + 1];//此处，不是用sizeof() 函数，注意区别  
//		strcpy((char*)myValueEx, strPath);
//		TCHAR lastChar = ((LPTSTR)PerfData)[cbData - 2];//字符串以\0结尾  
//		if (lastChar != ';')
//		{
//			strcpy((char*)myValueEx, ";");
//			strcat((char*)myValueEx, strPath);
//			//printf("%s %s\n",strPath,myValueEx);  
//			//printf("%d %d\n",strlen(strPath),strlen((char*)myValueEx)); 
//		}
//
//		CString strMyValueEx;
//		USES_CONVERSION;
//		strMyValueEx = A2T((LPCSTR)myValueEx);
//		//MessageBox(NULL,strMyValueEx,_T("信息"),MB_OK);
//
//		TCHAR * temp = new TCHAR[cbData + strlen((char*)myValueEx)];
//		_tcscpy_s(temp, cbData, (LPTSTR)PerfData);//拷贝path中原有的字符串到temp中   
//		//printf("temp:%s\n\n",temp);  
//
//		LPTSTR pathValue = _tcscat(temp, strMyValueEx);  //类似memcpy           
//		//printf("pathValue:%s\n\n",pathValue);  
//
//		long setResult = RegSetValueEx(hkResult, myVariable, 0, /*REG_SZ*/REG_EXPAND_SZ, (LPBYTE)pathValue, _tcsclen(pathValue) * sizeof(TCHAR));//设置某子键下特定名称的值。  
//		DWORD dwResult;
//		SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, LPARAM(_T("Environment")), SMTO_ABORTIFHUNG, 5000, &dwResult);//广播立即执行  
//		/*if(ERROR_SUCCESS == setResult)
//		{
//			MessageBox(NULL,_T("环境变量设置完成！"),_T("信息"),MB_OK);
//		}
//		else
//		{
//			MessageBox(NULL,_T("环境变量设置失败！"),_T("信息"),MB_OK);
//		}*/
//		delete[]myValueEx;
//		delete[]temp;
//		temp = NULL;
//	}
//	else
//	{
//		MessageBox(NULL, _T("环境变量读取失败！"), _T("信息"), MB_OK);
//	}
//	//printf("\nEnd Register\n");
//	RegCloseKey(hkResult);//释放键句柄 
//	free(PerfData);
//	PerfData = NULL;
//	//printf("\nEnd AddPath\n");
//	return 1;
//}
//
//int IsPathExist(void *PerfData, char *myPath)
//{
//	//return 0 ;
//	char * myoldPath = (char*)PerfData;
//	int i = 0;
//	while (myoldPath[i] != '\0')
//	{
//		i = i + 2;
//	}
//	char * path_t = new char[i / 2 + 2];
//
//	i = 0;
//	while (myoldPath[i] != '\0')
//	{
//		path_t[i / 2] = myoldPath[i];
//		i = i + 2;
//	}
//	path_t[i / 2] = '\0';
//	path_t[i / 2 + 1] = '\0';
//
//	CString strMyoldPath;
//	CString strMyPath;
//	USES_CONVERSION;
//	strMyoldPath = A2T((LPCSTR)path_t);
//	strMyPath = A2T((LPCSTR)myPath);
//
//	if (strMyoldPath[strMyoldPath.GetLength() - 1] != ';')
//	{
//		strMyoldPath = strMyoldPath + _T(";");
//	}
//	if (strMyPath[strMyPath.GetLength() - 1] != ';')
//	{
//		strMyPath = strMyPath + _T(";");
//	}
//
//
//	if (-1 == strMyoldPath.Find(strMyPath, 0))
//	{
//		delete path_t;
//		return 0;
//	}
//
//	delete path_t;
//	return 1;
//}