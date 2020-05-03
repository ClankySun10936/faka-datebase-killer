#pragma once
#include <iostream>
#include <time.h>
#include <cstring>
#include <Windows.h>
#include <fstream>
#include <cassert>
#include <string>
#include<cstdio>

#define cmd_utf_8 system("chcp 65001")
using namespace std;

string UTF8ToGBK(string& strUtf8)  //disabled
{
	string strOutGBK = "";
	int len = MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, NULL, 0);
	WCHAR* wszGBK = new WCHAR[len + 1];
	memset(wszGBK, 0, len * 2 + 2);
	MultiByteToWideChar(CP_UTF8, 0, strUtf8.c_str(), -1, wszGBK, len);
	len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
	char* pszGBK = new char[len + 1];
	memset(pszGBK, 0, len + 1);
	WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, pszGBK, len, NULL,	 NULL);
	strOutGBK = pszGBK;
	delete[]pszGBK;
	delete[]wszGBK;
	return strOutGBK;
}

string GetRandomStr(int bit)  //bit为生成的位数
{
	char* output = new   char[bit];
	srand((unsigned)time(NULL));
	char   c;
	for (int a = 0; a < bit; a++) {
		c = ((rand() % 74) + 48);
		while (!IsCharAlphaNumeric(c)) {
			c = ((rand() % 74) + 48);
		}
		output[a] = c;
	}
	output[bit] = '\0';
	string   out(output);
	return   out;
}

void update_log(string file,string updatedate)
{

	system("title 更新日志");
	system("color 0a");
	ifstream infile;
	infile.open(file.data());   //将文件流对象与文件连接起来 
	assert(infile.is_open());   //若失败,则输出错误消息,并终止程序运行 

	string s;
	while (getline(infile, s))
	{
		cout << s << endl;
	}
	infile.close();             //关闭文件输入流 

	cout << "\n\nby 昕辰丶 & fnardn updated at" << updatedate << endl;
	
	system("pause");
}