#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<deque>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<numeric>
#include"Speaker.h"
using namespace std;

//宏定义姓、名
#define FIRST_NAME "赵钱孙李周吴郑王冯陈褚卫蒋沈韩杨"
#define MID_NAME "伯仲叔季大二三小甲乙丙丁子丑寅卯"
#define LAST_NAME  "杰婕洁捷冰炳楠囡雨予丹儋擅缮林麟"



class SpeakerManager
{
public:
	SpeakerManager();
	~SpeakerManager();

	//初始化系统函数
	void initSystem();

	//显示主界面函数
	void showMenu();

	//退出系统函数
	void exitMenu();

	//创建员工函数
	void createSpeaker();

	//抽签分组函数
	void setGroup();

	//单个选手打分函数
	double setSingleScore();

	//全员打分晋级函数
	void setAllScore();

	//展示选手信息函数
	void showInfo();

	//进行比赛函数
	void runCompetition();

public:

	//装载所有选手编号的容器
	vector<int>vectorSpeaker;

	//装载一组选手编号的容器
	vector<int>vectorSpeaker1;

	//装载二组选手编号的容器
	vector<int>vectorSpeaker2;

	//装载晋级选手编号的容器
	vector<int>vectorUpperSpeaker;

	//装载胜利选手编号的容器
	vector<int>vectorWinSpeaker;

	//装载所有选手编号和选手的容器
	map<int, Speaker>mapSpeaker;

	//当前比赛轮数
	int roundNum;

	//创建打分表
	deque<double>dequeScore;
};
