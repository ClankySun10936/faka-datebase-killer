#include"Faka_Killer.h"
#include"curl.h"
#include"Xpython,h.h"

#define cmd_utf_8 system("chcp 65001")

using namespace std;

#ifndef _WIN32
cout << "��ʹ��windowsƽ̨���д˳���!" << endl;
system("pause");
return false;
#endif

char choose_id;

int main()
{

	update_log("update.txt", "2020/5/2"); //ANSI
	system("title ���������ݿ�ɱ��");

	cout << "\n\n������ʹ�õ�ģ����\n1.curl\n2.python(put)\n";
main_read:
	cin >> choose_id;

	if (int(choose_id) - int('0') < 1 || int(choose_id) - int('0') > 9)
	{
		printf("�����������������\n");
		goto main_read;
	}

	switch (int(choose_id) - int('0')) {
	case 1:curl_auto_read(); break;
	case 2:py_put(); break;
		default: {
		cout << "����δ�ҵ�,����������:\n";
		goto main_read;
		}
	}	

	return false;
}