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
//	HKEY hkResult;//���ľ��
//	LPCTSTR environmentKey = _T("SYSTEM\\CurrentControlSet\\Control\\Session Manager\\Environment");
//	//HKEY_CURRENT_USER   HKEY_LOCAL_MACHINE
//	//LPCTSTR environmentKey =_T("Environment");
//	if (ERROR_SUCCESS != RegOpenKeyEx(HKEY_LOCAL_MACHINE, environmentKey, 0, KEY_SET_VALUE | KEY_READ, &hkResult)) //�򿪼�environment     
//	{
//		MessageBox(NULL, _T("����ע������\n��ʹ�ù���Ա�ʻ�ִ�б�����"), _T("ERROR"), MB_ICONERROR);
//		return 0;
//	}
//	DWORD BufferSize = 8192;   //���ݳ���   
//	DWORD cbData;    ////���ݳ���   
//	DWORD dwRet;
//	VOID* PerfData = malloc(BufferSize);//���ݴ�ŵ�ַ     
//	cbData = BufferSize;
//
//	LPCTSTR myVariable = _T("PATH");//��������    
//	dwRet = RegQueryValueEx(hkResult, myVariable, NULL, NULL, (LPBYTE)PerfData, &cbData); //��ȡĳ�Ӽ����ض����Ƶ�ֵ       
//	while (dwRet == ERROR_MORE_DATA)
//	{
//		BufferSize += 4096;
//		PerfData = realloc(PerfData, BufferSize);
//		cbData = BufferSize;
//		dwRet = RegQueryValueEx(hkResult, myVariable, NULL, NULL, (LPBYTE)PerfData, &cbData);
//	}
//	//MessageBox(NULL,(LPCTSTR)PerfData,_T("�ҵ�ϵͳ����Path"),MB_OK);
//
//	if (dwRet == ERROR_SUCCESS)//���Ʋ�����ʱ�����������Ʋ��趨��ֵ    
//	{
//		//�ж��Ƿ����myValue  
//		if (IsPathExist(PerfData, strPath))
//		{
//			//MessageBox(NULL,_T("���������Ѿ����ڣ�"),_T("��Ϣ"),MB_OK);
//			RegCloseKey(hkResult);//�ͷż���� 
//			free(PerfData);
//			return 1;
//		}
//
//		LPTSTR myValueEx = new TCHAR[strlen(strPath) + 1];//�˴���������sizeof() ������ע������  
//		strcpy((char*)myValueEx, strPath);
//		TCHAR lastChar = ((LPTSTR)PerfData)[cbData - 2];//�ַ�����\0��β  
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
//		//MessageBox(NULL,strMyValueEx,_T("��Ϣ"),MB_OK);
//
//		TCHAR * temp = new TCHAR[cbData + strlen((char*)myValueEx)];
//		_tcscpy_s(temp, cbData, (LPTSTR)PerfData);//����path��ԭ�е��ַ�����temp��   
//		//printf("temp:%s\n\n",temp);  
//
//		LPTSTR pathValue = _tcscat(temp, strMyValueEx);  //����memcpy           
//		//printf("pathValue:%s\n\n",pathValue);  
//
//		long setResult = RegSetValueEx(hkResult, myVariable, 0, /*REG_SZ*/REG_EXPAND_SZ, (LPBYTE)pathValue, _tcsclen(pathValue) * sizeof(TCHAR));//����ĳ�Ӽ����ض����Ƶ�ֵ��  
//		DWORD dwResult;
//		SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0, LPARAM(_T("Environment")), SMTO_ABORTIFHUNG, 5000, &dwResult);//�㲥����ִ��  
//		/*if(ERROR_SUCCESS == setResult)
//		{
//			MessageBox(NULL,_T("��������������ɣ�"),_T("��Ϣ"),MB_OK);
//		}
//		else
//		{
//			MessageBox(NULL,_T("������������ʧ�ܣ�"),_T("��Ϣ"),MB_OK);
//		}*/
//		delete[]myValueEx;
//		delete[]temp;
//		temp = NULL;
//	}
//	else
//	{
//		MessageBox(NULL, _T("����������ȡʧ�ܣ�"), _T("��Ϣ"), MB_OK);
//	}
//	//printf("\nEnd Register\n");
//	RegCloseKey(hkResult);//�ͷż���� 
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