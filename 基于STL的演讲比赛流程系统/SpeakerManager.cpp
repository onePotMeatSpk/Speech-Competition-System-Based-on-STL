#include"SpeakerManager.h"


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
	//确保容器中为空
	vectorSpeaker.clear();
	vectorUpperSpeaker.clear();
	vectorWinSpeaker.clear();
	mapSpeaker.clear();

	//宏定义默认分数
	double defaultScore[] { 0 , 0 };

	//创建选手并填入容器中
	for (int i = 0; i < 12; i++)
	{
		//初始化选手
		Speaker s("", defaultScore);
		
		//为选手分配编号与名字
		int randNum = rand() % 16;
		s.s_name += FIRST_NAME[randNum * 2];
		s.s_name += FIRST_NAME[randNum * 2 + 1];
		randNum = rand() % 16;
		s.s_name += MID_NAME[randNum * 2];
		s.s_name += MID_NAME[randNum * 2 + 1];
		randNum = rand() % 16;
		s.s_name += LAST_NAME[randNum * 2];
		s.s_name += LAST_NAME[randNum * 2 + 1];

		//将选手的编号装填进vector容器中
		vectorSpeaker.push_back(i);

		//将选手编号和选手装填进pair中
		pair<int, Speaker>p(i, s);

		//将pair装填进map容器中
		mapSpeaker.insert(p);
		cout << mapSpeaker.at(i).s_name << endl;
	}
}

//展示选手信息函数
void showInfo()
{
	
}


