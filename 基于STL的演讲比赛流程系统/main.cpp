#include<iostream>
#include"SpeakerManager.h"
using namespace std;

int main()
{
	//��ʼ��ϵͳ
	SpeakerManager sm;
	int choice;
	srand((unsigned int)time(NULL));

	while (true)
	{
		//��ʾ������
		sm.showMenu();

		//ѡ����
		choice = -1;
		cout << "������Ҫ���еĹ��ܣ�";
		cin >> choice;
		switch (choice)
		{
			//ѡ��0:�˳�ϵͳ
		case 0:
			sm.exitMenu();
			break;
			//ѡ��1����ʼ�ݽ�����
		case 1:
			sm.runCompetition();
			break;
			//ѡ��2�����������¼

			//ѡ��3����ձ�����¼

		default:
			cout << "??������ȷ����??" << endl;
			system("pause");
			system("cls");
			break;
		}
		
	}
}
