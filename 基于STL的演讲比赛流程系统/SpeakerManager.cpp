#include"SpeakerManager.h"

string FIRST_NAME = "赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨";
string MID_NAME = "伯仲叔季大二三小甲乙丙丁子丑寅卯";
string LAST_NAME = "杰婕洁捷冰炳楠囡雨予丹儋擅缮林麟";

SpeakerManager::SpeakerManager()
{
}

SpeakerManager::~SpeakerManager()
{
}

//显示主界面函数
void SpeakerManager::showMenu()
{
	cout << "**************************************" << endl;
	cout << "**/----------比赛管理系统----------\\**" << endl;
	cout << "**|          1.开始比赛            |**" << endl;
	cout << "**|          2.查看往届记录        |**" << endl;
	cout << "**|          3.清空比赛记录        |**" << endl;
	cout << "**|          0.退出系统            |**" << endl;
	cout << "**\\--------------------------------/**" << endl;
	cout << "**************************************" << endl;
}

//退出系统函数
void SpeakerManager::exitMenu()
{
	cout << "**************************************" << endl;
	cout << "******  谢谢使用，系统正在关闭  ******"<<endl;
	cout << "**************************************" << endl;
	system("pause");
	exit(0);
}

//创建选手函数
void SpeakerManager::createSpeaker()
{
	//创建选手并填入容器中
	for (int i = 0; i < 12; i++)
	{
		double score[] = { 0 , 0 };
		Speaker p("选手", score);
	}
	

}


