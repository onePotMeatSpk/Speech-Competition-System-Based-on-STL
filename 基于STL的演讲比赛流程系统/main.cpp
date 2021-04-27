#include<iostream>
#include"SpeakerManager.h"
using namespace std;

int main()
{
	//初始化系统
	SpeakerManager sm;
	int choice;

	while (true)
	{
		//显示主界面
		sm.showMenu();

		//选择功能
		choice = -1;
		cout << "请输入要进行的功能：";
		cin >> choice;
		switch (choice)
		{
			//选择0:退出系统
		case 0:
			sm.exitMenu();

			//选择1：开始演讲比赛
		
			//选择2：查拉往届记录

			//选择3：清空比赛记录

		default:
			cout << "??输入正确数字??" << endl;
			system("pause");
			system("cls");
			break;
		}
		

	}
}
