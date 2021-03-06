#include"SpeakerManager.h"


SpeakerManager::SpeakerManager()
{
	this->initSystem();
}

SpeakerManager::~SpeakerManager()
{
}

//初始化系统函数
void SpeakerManager::initSystem()
{
	//清空容器
	vectorSpeaker.clear();
	vectorSpeaker1.clear();
	vectorSpeaker2.clear();
	vectorUpperSpeaker.clear();
	vectorWinSpeaker.clear();
	mapSpeaker.clear();
	dequeScore.clear();

	//置零比赛轮数
	roundNum = 0;
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
		//初始化选手
		Speaker s;
		
		//为选手取名字
		//姓
		int randNum = rand() % 16;
		s.s_name += FIRST_NAME[randNum * 2];//汉字是占两个字节的字符，故而需要加两次才能得到一个完整的汉字字符
		s.s_name += FIRST_NAME[randNum * 2 + 1];//只加一次，结果一般会是一些奇奇怪怪的生僻汉字
		//名首字
		randNum = rand() % 16;
		s.s_name += MID_NAME[randNum * 2];
		s.s_name += MID_NAME[randNum * 2 + 1];
		//名尾字
		randNum = rand() % 16;
		s.s_name += LAST_NAME[randNum * 2];
		s.s_name += LAST_NAME[randNum * 2 + 1];

		//将选手的编号装填进vector容器中
		vectorSpeaker.push_back(i);

		//将选手编号和选手配对，装填进pair中
		pair<int, Speaker>p(i, s);

		//将pair装填进map容器中
		mapSpeaker.insert(p);
	}

	
}

//抽签分组函数
void SpeakerManager::setGroup()
{
	if (roundNum == 1)
	{
		vectorSpeaker1.resize(6);
		vectorSpeaker2.resize(6);
		random_shuffle(vectorSpeaker.begin(), vectorSpeaker.end());
		copy(vectorSpeaker.begin(), vectorSpeaker.begin() +6, vectorSpeaker1.begin());
		copy(vectorSpeaker.begin() + 6, vectorSpeaker.end(), vectorSpeaker2.begin());
	}
	else
	{
		random_shuffle(vectorUpperSpeaker.begin(), vectorUpperSpeaker.end());
	}

	
}

//单个选手打分函数
double SpeakerManager::setSingleScore()
{
	dequeScore.clear();//清空打分表
	for (int i = 0; i < 10; i++)
	{
		dequeScore.push_back(rand() % 100);//随机打分
	}
	sort(dequeScore.begin(), dequeScore.end());//从低到高排列分数
	dequeScore.pop_front();//去除最低分
	dequeScore.pop_back();//去除最高分
	double score = accumulate(dequeScore.begin(), dequeScore.end(), 0) / 8;//计算平均分
	return score;
}

//全员打分晋级函数
void SpeakerManager::setAllScore()
{
	multimap<double, int, greater<double>>mapBuffer;
	
	if (roundNum == 1)//第一轮比赛打分
	{
		vectorUpperSpeaker.clear();
		//第一组打分
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorSpeaker1.begin(); 
			it != vectorSpeaker1.end(); it++)
		{
				//将分数载入选手信息中
				mapSpeaker.at(*it).s_score[0] = setSingleScore();

				mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[0], *it));
				
		}
		//晋级
		int index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorUpperSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}


		//第二组打分
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorSpeaker2.begin();it != vectorSpeaker2.end(); it++)
		{
			//将分数载入选手信息中
			mapSpeaker.at(*it).s_score[0] = setSingleScore();

			
			mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[0], *it));
			
		}
		//晋级
		index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorUpperSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}


	}
	else//第二轮比赛打分
	{
		vectorWinSpeaker.clear();
		mapBuffer.clear();
		for (vector<int>::iterator it = vectorUpperSpeaker.begin(); it != vectorUpperSpeaker.end(); it++)
		{
			mapSpeaker.at(*it).s_score[1] = setSingleScore();

			//晋级
			mapBuffer.insert(make_pair(mapSpeaker.at(*it).s_score[1], *it));
			
		}
		int index_mapBuffer = 0;
		for (multimap<double, int, greater<double>>::iterator it_mapBuffer = mapBuffer.begin(); index_mapBuffer < 3 && it_mapBuffer != mapBuffer.end(); it_mapBuffer++)
		{
			vectorWinSpeaker.push_back(it_mapBuffer->second);
			index_mapBuffer++;
		}
	}
}


//展示选手信息函数
void SpeakerManager::showInfo()
{
	if (roundNum==1)
	{
		cout << "************第一轮比赛结果************" << endl;
		cout << "****第一组****" << endl;
		for (vector<int>::iterator it = vectorSpeaker1.begin();
			it != vectorSpeaker1.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[0] << " ";
			if (find(vectorUpperSpeaker.begin(),vectorUpperSpeaker.end(),*it)!=vectorUpperSpeaker.end())
			{
				cout << "该选手晋级" << endl;
			}
			else
			{
				cout << endl;
			}
		}

		cout << "****第二组****" << endl;
		for (vector<int>::iterator it = vectorSpeaker2.begin();
			it != vectorSpeaker2.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[0] << " ";
			if (find(vectorUpperSpeaker.begin(), vectorUpperSpeaker.end(), *it) != vectorUpperSpeaker.end())
			{
				cout << "该选手晋级" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
	else
	{
		cout << "************第二轮比赛结果************" << endl;
		for (vector<int>::iterator it = vectorUpperSpeaker.begin();
			it != vectorUpperSpeaker.end(); it++)
		{
			cout << mapSpeaker.at(*it).s_name << ": " << mapSpeaker.at(*it).s_score[1] << " ";
			if (find(vectorWinSpeaker.begin(), vectorWinSpeaker.end(), *it) != vectorWinSpeaker.end())
			{
				cout << "该选手获胜" << endl;
			}
			else
			{
				cout << endl;
			}
		}
	}
}


//进行比赛函数
void SpeakerManager::runCompetition()
{
	this->roundNum = 1;
	this->createSpeaker();
	this->setGroup();
	this->setAllScore();
	this->showInfo();
	this->roundNum = 2;
	this->setGroup();
	this->setAllScore();
	this->showInfo();
}

