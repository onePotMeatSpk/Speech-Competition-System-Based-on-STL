#pragma once
#include<iostream>
#include<vector>
#include<map>
#include<stdlib.h>
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

	//显示主界面函数
	void showMenu();

	//退出系统函数
	void exitMenu();

	//创建员工函数
	void createSpeaker();

	//展示选手信息函数
	void showInfo();

public:

	//创建一个装载所有选手编号的容器
	vector<int>vectorSpeaker;

	//创建一个装载晋级选手编号的容器
	vector<int>vectorUpperSpeaker;

	//创建一个装载胜利选手编号的容器
	vector<int>vectorWinSpeaker;

	//创建一个装载所有选手编号和选手的容器
	map<int, Speaker>mapSpeaker;

};
